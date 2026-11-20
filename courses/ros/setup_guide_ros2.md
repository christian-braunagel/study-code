# ROS 2 Setup Guide

This guide uses **ROS 2 Lyrical Luth**. Use the section for your operating system and verify your installation at the end. [Official ROS 2 Lyrical installation overview](https://docs.ros.org/en/lyrical/Get-Started/Installation.html)

| Operating system | Setup for the course |
| --- | --- |
| [Windows 10 or 11](#windows) | Install ROS 2 Lyrical Desktop in Ubuntu 26.04 LTS on WSL 2. |
| [Ubuntu Linux](#ubuntu-linux) | Install `ros-lyrical-desktop` directly on Ubuntu 26.04 LTS. |
| [macOS](#macos) | Run Ubuntu 26.04 LTS in a virtual machine such as VMware Fusion, then follow the Ubuntu Linux steps. |

## Suggestion for IDE: Visual Studio Code
If you not already have an IDE, we recommend **Visual Studio Code**. It is free, open-source, and works on Windows, Linux, and macOS. [Official Visual Studio Code download page](https://code.visualstudio.com/)

Install the extension wsl-vscode to use Visual Studio Code with WSL 2. [Official Visual Studio Code WSL extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl)

## Windows

With WSL 2, you run ROS 2 in an Ubuntu terminal from Windows. WSL 2 requires hardware virtualization.

### Check hardware virtualization

Press **Ctrl + Shift + Del** to open Task Manager. If you see the compact view, select **More details**. Go to **Performance > CPU** and look for **Virtualization** below the graph. If it says **Enabled**, continue to the WSL check below.

If it says **Disabled**, enable virtualization in your PC's UEFI or BIOS.
 [Microsoft's virtualization guide and manufacturer instructions](https://support.microsoft.com/en-us/windows/experience/enable-virtualization-on-windows)

### Check whether WSL is installed

On Windows 10 or 11, open PowerShell and run the following commands. [Microsoft's WSL command reference](https://learn.microsoft.com/en-us/windows/wsl/basic-commands)

```powershell
wsl --status
wsl --list --verbose
```

- If `wsl --status` shows WSL configuration such as `Default Version: 2`, WSL is installed. If `Ubuntu-26.04` is missing from the list, start at step 1 of [Install Ubuntu 26.04 in WSL](#install-ubuntu-2604-in-wsl).
- If the list already shows `Ubuntu-26.04`, skip to step 2 of [Install Ubuntu 26.04 in WSL](#install-ubuntu-2604-in-wsl). The `VERSION` column shows whether that distribution uses WSL 1 or 2.
- If PowerShell cannot find `wsl`, or WSL says it needs to be installed, follow the steps for your Windows version below.

### Install WSL on Windows 10

1. Press **Win + R**, enter `winver`, and check your Windows version. Canonical's Ubuntu-on-WSL instructions require version **21H2 (build 19044) or newer**. [Canonical's Ubuntu on WSL requirements](https://ubuntu.com/wsl/docs/latest/howto/install-ubuntu-wsl2/)
2. Open **PowerShell as Administrator** and enable WSL without installing the default Linux distribution.

   ```powershell
   wsl --install --no-distribution
   ```

3. Restart Windows and continue with [Install Ubuntu 26.04 in WSL](#install-ubuntu-2604-in-wsl). If the install command is unavailable, you can try the manual steps [Microsoft's manual WSL installation guide](https://learn.microsoft.com/en-us/windows/wsl/install-manual).

### Install WSL on Windows 11

1. Open **Windows Terminal** or **PowerShell** as Administrator. Enable WSL with the following command. [Microsoft's WSL installation guide](https://learn.microsoft.com/en-us/windows/wsl/install)

   ```powershell
   wsl --install --no-distribution
   ```

2. Restart Windows and continue with [Install Ubuntu 26.04 in WSL](#install-ubuntu-2604-in-wsl).

### Install Ubuntu 26.04 in WSL

1. Open PowerShell and run these commands. `wsl --list --online` should include `Ubuntu-26.04`. If it is missing, Canonical also provides a downloadable `.wsl` image. [Canonical's Ubuntu on WSL installation guide](https://ubuntu.com/wsl/docs/latest/howto/install-ubuntu-wsl2/)

   ```powershell
   wsl --update
   wsl --set-default-version 2
   wsl --list --online
   wsl --install -d Ubuntu-26.04
   ```

2. Launch **Ubuntu 26.04** from the Start menu or run `wsl -d Ubuntu-26.04`. Create a Linux username and password when prompted.
3. Run `wsl --list --verbose` in PowerShell and check that the Ubuntu entry shows **VERSION 2**. If it shows `1`, run `wsl --set-version Ubuntu-26.04 2`. Use the distribution name shown in the list if it differs. [Microsoft's WSL command reference](https://learn.microsoft.com/en-us/windows/wsl/basic-commands)
4. In the **Ubuntu terminal**, follow the [Ubuntu Linux](#ubuntu-linux) steps below.

## Ubuntu Linux

Use **Ubuntu 26.04 LTS (Resolute Raccoon)**. Run the commands in Bash on Ubuntu or inside Ubuntu 26.04 on WSL 2. [Official ROS 2 Lyrical installation guide for Ubuntu](https://docs.ros.org/en/lyrical/Get-Started/Installation/Ubuntu-Install-Debs.html)

1. Run `locale` and check that your locale uses UTF-8. If it already does, continue to step 2. Otherwise, set up a UTF-8 locale, for example `en_US.UTF-8`.

   ```bash
   sudo apt update
   sudo apt install locales
   sudo locale-gen en_US.UTF-8
   sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
   export LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
   locale
   ```

2. Enable Ubuntu's Universe repository.

   ```bash
   sudo apt update
   sudo apt install software-properties-common
   sudo add-apt-repository universe
   ```

3. Install `ros2-apt-source` to configure the ROS 2 APT repository and its signing key. [Official ROS APT source releases](https://github.com/ros-infrastructure/ros-apt-source/releases)

   ```bash
   sudo apt update && sudo apt install curl -y
   
   export ROS_APT_SOURCE_VERSION=$(curl -fsSL -o /dev/null -w '%{url_effective}' https://github.com/ros-infrastructure/ros-apt-source/releases/latest | awk -F/ '{print $NF}')
   
   curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo ${UBUNTU_CODENAME:-${VERSION_CODENAME}})_all.deb"
   
   sudo dpkg -i /tmp/ros2-apt-source.deb
   ```

4. To build ROS packages, install the optional development tools.

   ```bash
   sudo apt update && sudo apt install ros-dev-tools
   ```

5. Refresh the package lists and upgrade Ubuntu packages.

   ```bash
   sudo apt update
   sudo apt upgrade
   ```

6. Install ROS 2 Lyrical Desktop. The desktop package includes RViz and demo nodes.

   ```bash
   sudo apt install ros-lyrical-desktop
   ```

7. Add the ROS setup command to `~/.bashrc` so new Bash terminals load the ROS environment automatically. Reload `~/.bashrc` to apply the change in the current terminal.

   The `~` stands for your Ubuntu user's home directory, so `~/.bashrc` is usually `/home/<username>/.bashrc`. The leading dot makes it a hidden file. Run `ls -a ~` in the Ubuntu terminal to see it.

   ```bash
   echo 'source /opt/ros/lyrical/setup.bash' >> ~/.bashrc
   source ~/.bashrc
   ```

8. Verify that the C++ talker and Python listener can exchange messages. In the current terminal, run the talker.

   ```bash
   ros2 run demo_nodes_cpp talker
   ```

   Keep the talker running. Open a second Ubuntu terminal and start the listener.

   ```bash
   ros2 run demo_nodes_py listener
   ```

   The listener should print the `Hello World` messages published by the talker. Press **Ctrl+C** in each terminal to stop the demo.

## macOS

You can install ROS 2 on macOS, but there is an important limitation: __macOS is not a primary supported platform for ROS 2 binary installations!__ Unlike Ubuntu, you generally cannot install ROS 2 simply using apt.

Suggestion for macOS: Use a virtual machine such as VMware Fusion to run Ubuntu 26.04 LTS. Then follow the [Ubuntu Linux](#ubuntu-linux) steps above.

## Verify the installation

Run the following in your Ubuntu terminal, Ubuntu on WSL, or inside the ROS Docker container.

```bash
printenv ROS_DISTRO
ros2 --help
```

You should see `lyrical` followed by the ROS 2 command-line help.
