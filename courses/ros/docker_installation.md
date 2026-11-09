# Getting Started with Docker and ROS

To enable a smooth experience with ROS (Robot Operating System) in our lecture, I highly recommend using Docker. Docker allows you to run applications in isolated containers, ensuring that your ROS environment is consistent across different systems. Below, you can find the steps to install Docker on your operating system and run your first ROS container.

## Docker Installation (Windows, Linux, macOS)

Follow the official Docker installation guide:

[Docker – Get Docker (Official Documentation)](https://docs.docker.com/get-started/get-docker/)

Select your operating system and follow the corresponding installation instructions.

## 1. Windows

- Install **Docker Desktop for Windows**.
- Docker Desktop typically uses the **Windows Subsystem for Linux 2 (WSL 2)** backend.
- If WSL 2 is not installed, open PowerShell as Administrator and execute:

  ```powershell
  wsl --install
  ```

- Restart your computer if prompted.
- Ensure that hardware virtualization is enabled.
- Install and launch Docker Desktop. Make sure the WSL 2 backend is enabled.

## 2. Linux

- Install **Docker Engine** using the instructions for your Linux distribution (e.g., Ubuntu or Debian).
- Start the Docker service if it is not already running.
- Optionally, configure Docker to run without `sudo` by adding your user to the `docker` group. Note that this grants root-equivalent privileges.

## 3. macOS

- Download and install **Docker Desktop for Mac**.
- Choose the correct version for your processor (Apple Silicon or Intel).
- Launch Docker Desktop and complete the initial setup.

## 4. Verify the installation

After installation, open a terminal (PowerShell on Windows) and execute:

```bash
docker --version
docker run hello-world
```

The first command displays the installed Docker version. The second downloads and runs a test container to verify that Docker is working correctly.

**Important:** Docker Desktop must be running on Windows and macOS before executing Docker commands. On Linux, the Docker daemon must be running.

## Running ROS in Docker

### 1. Download the ROS 2 Jazzy Jalisco image

The lecture uses **ROS 2 Jazzy Jalisco**. The official `ros:jazzy-ros-base-noble` image provides ROS 2 command-line tools and libraries on Ubuntu 24.04 (Noble). ROS does not need to be installed on your host computer.

Run the following commands in your host terminal (PowerShell on Windows, or a terminal on Linux/macOS). On Windows, Docker Desktop must use **Linux containers**.

```bash
docker pull ros:jazzy-ros-base-noble
```

Use this explicit tag to select Jazzy rather than relying on `latest`, which can change to another ROS distribution.

### 2. Create a persistent ROS container (first session)

```bash
docker run --name ros-jazzy -it ros:jazzy-ros-base-noble bash
```

- `--name ros-jazzy` gives the container a name for use in later commands.
- `-it` opens an interactive terminal.
- `bash` starts a Bash shell inside the container.

Run this command only once to create the container. For later sessions, restart this same container as described below.

You are now working inside the Linux container, even if your host runs Windows or macOS. The image's entrypoint loads the ROS environment automatically. Verify it inside the container:

```bash
printenv ROS_DISTRO
ros2 --help
```

The first command should print `jazzy`; the second should display the ROS 2 command-line help.

### 3. Stop and resume the container

To leave the container shell and stop the container, type:

```bash
exit
```

The container remains on your computer, including any packages you install and files you create. To resume it in your next session, run this command in a host terminal:

```bash
docker start -ai ros-jazzy
```

This restarts the existing container and attaches your terminal to its Bash shell. The ROS environment is loaded automatically again.

Use `docker run` to create the container once and `docker start -ai ros-jazzy` for subsequent sessions. Running `docker run --name ros-jazzy ...` again fails while a container with that name already exists, even if it is stopped. To see running and stopped containers, use:

```bash
docker ps -a
```

Files and installed packages survive stopping and restarting because the container was created without `--rm`. They are lost if the container is deleted. Keep important source code in a mounted host folder (bind mount) or Docker volume so it also survives container deletion.

For image details, see the [official ROS Docker image documentation](https://hub.docker.com/_/ros/) and the [ROS Jazzy image announcement](https://discourse.ros.org/t/ros-jazzy-docker-images/37879).
