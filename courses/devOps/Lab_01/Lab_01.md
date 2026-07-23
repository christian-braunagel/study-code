# Lab 1: GitLab for Beginners

This lab focuses on getting started with GitLab.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Create a GitLab account
All exercises of this DevOps course require you to have a working GitLab account.
GitLab accounts are free and do not require any billing information in it's basic version.
Hence, this will be your first task:

### Task Description

* Navigate to [https://gitlab.com/](https://gitlab.com/)
* Create a new account
* Afterwards, log into your account for the first time and explore the GitLab homepage (especially your user settings)
* Feel free to update your account information
* Moreover, check out the extensive documentation of [GitLab](https://docs.gitlab.com/). It will be an important source of information throughout the course

## 🟢 Section II: Setup your SSH key

SSH keys provide a secure way to authenticate with remote Git repositories without entering your password each time. In this section, you will generate an SSH key pair and connect it to your GitLab account.

### Task Description

* Login to your account
* navigate to your user settings by clicking on your profile picture on the top right corner
* In the drop down box, select ```edit profile``` to open the user settings
* Select ```Access``` then ```SSH keys```
* Here you can add new SSH keys or revoke/remove existing keys
* Add a new ssh key by following the [GitLab Documentation](https://docs.gitlab.com/user/ssh/)

## 🟢 Section III: Create your first repository on GitLab

Git repositories are used to store and manage your source code together with its complete version history. In this section, you will create your first GitLab repository and prepare it for future development tasks.

### Task Description

* Login to your GitLab account
* On the GitLab homepage, select `New project`
* Choose `Create blank project`
* Enter a repository name, e.g. `devops-lab`
* Set the visibility level to `Private`
* Enable the option to initialize the repository with a `README`
* Click `Create project`
* Explore the repository overview page and familiarize yourself with the available menus and features
* Setup the project structure by creating the following folders and files:
  * `src/` - This folder will contain your source code files
  * `docs/` - This folder will contain your documentation files
  * `README.md` - This file will provide an overview of your project
  * `LICENSE` - This file will contain the license information for your project
  * `include/` - This folder will contain your header files
  * `tests/` - This folder will contain your test files
  * `scripts/` - This folder will contain your scripts for automation and deployment
  * `lib/` - This folder will contain any external libraries or dependencies used in your project

## 🟢 Section IV: Explore the Thoughtworks Technology Radar

Browse and investigate the current Thoughtworks Technology Radar. It is a great source of information about the current state of software development and technology trends. Identify all the tools that you would allocate to the domain of DevOps and create a list of them. You can find the Technology Radar at [https://www.thoughtworks.com/radar](https://www.thoughtworks.com/radar).
