# Lab 3: YAML and Docker Basics

This lab focuses on two important DevOps building blocks: writing structured configuration files with YAML and running software in containers with Docker.

All sections of this lab are based on the following levels of difficulty:

🟢 __Simple__: A guided task that focuses on learning the basics. It should not take more than 15 minutes to finish.

🟡 __Moderate__: A task that tests your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30 minutes depending on your knowledge.

🔴 __Complex__: A difficult or longer task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. These tasks might take up to a few hours.

## 🟢 Section I: Embedded System Configuration in YAML Format

In this exercise, you will create a YAML file for a small embedded control unit.
YAML is often used for configuration files because it is readable for humans and easy to process with tools.

### Task Description

An embedded device controls temperature and status signals.

The device contains:

- one microcontroller
- two sensors
- two LEDs

Create a file called `embedded_system_config.yaml`.

### 1. Device Information

Create a device structure on the top level including the fields:

- `name`
- `version`
- `manufacturer`
- `active`
- `microcontroller`
- `sensors`
- `leds`

### 2. Microcontroller

The microcontroller should contain:

- `type`, for example `STM32F103`
- `clock_frequency_mhz`, for example `72`
- `ram`, for example `20 KB`
- `watchdog_enabled`

### 3. Sensors

Create a list of two sensors.

Each sensor should contain:

- `name`
- `type`
- `unit`
- `calibrated`

Example sensor types:

- `temperature`
- `pressure`
- `voltage`

### 4. LEDs

Create a list of two LEDs.

Each LED should contain:

- `color`
- `function`
- `enabled`

### Requirements

- Use 2 spaces for indentation
- Use spaces, not tabs
- Use dictionaries and lists
- Use meaningful key names
- Store boolean values as `true` or `false`

### Final Check

At the end of this exercise, you should be able to explain:

- What a YAML key-value pair is
- How nested dictionaries are written in YAML
- How lists are written in YAML
- Why indentation is important in YAML

## 🟢 Section II: Basic Docker Concepts and Commands

Start by opening the official Docker setup page: [https://www.docker.com/get-started/](https://www.docker.com/get-started/)

Install Docker Desktop or check that Docker is already installed on your system.
In this exercise, you will learn the basic idea of containers and practice the most important Docker commands.

### Task Description

Create a small project folder called `docker-basics`.
Inside this folder, you will run existing container images and write down what you observe.

### 1. Check the Docker Installation

Open a terminal and run:

```bash
docker --version
docker info
```

If Docker is installed correctly, the first command should show the Docker version.
The second command should show information about your Docker installation.

### 2. Run Your First Container

Run the official hello-world image:

```bash
docker run hello-world
```

Afterwards, answer the following questions in a file called `docker_notes.md`:

- What happened when you started the container?
- Did Docker need to download an image first?
- What is the difference between an image and a container?

### 3. List Images and Containers

Use the following commands:

```bash
docker image ls
docker container ls
docker container ls -a
```

Add short answers to `docker_notes.md`:

- Which images are available locally?
- Why does `docker container ls` show fewer containers than `docker container ls -a`?

### 4. Run an Interactive Container

Start an interactive Ubuntu container:

```bash
docker run -it ubuntu bash
```

Inside the container, run:

```bash
pwd
ls
cat /etc/os-release
exit
```

Add the following answers to `docker_notes.md`:

- Which operating system is running inside the container?
- What happened when you typed `exit`?
- Why is this useful for development and testing?

### 5. Run a Web Server Container

Start an nginx web server container:

```bash
docker run --name lab-nginx -p 8080:80 -d nginx
```

Open your browser and navigate to:

```text
http://localhost:8080
```

Then inspect and stop the container:

```bash
docker container ls
docker logs lab-nginx
docker stop lab-nginx
docker rm lab-nginx
```

Add short explanations to `docker_notes.md`:

- What does `-p 8080:80` do?
- What does `-d` do?
- Why should stopped containers be removed when they are no longer needed?

### Final Check

At the end of this exercise, you should be able to explain:

- What Docker is used for
- What an image is
- What a container is
- How to start, list, stop, and remove containers
- How port mapping connects a container to your local machine

## 🟡 Section III: Describe a Container Setup with YAML

In this exercise, you will combine YAML and Docker by writing a Docker Compose file.
Docker Compose uses YAML to describe one or more containers that belong to the same application.

### Task Description

Extend the `docker-basics` project folder.
Create a file called `compose.yaml`.
The file should describe a small web server setup based on nginx.

### 1. Create a Compose File

Your `compose.yaml` should contain:

- one service called `web`
- the image `nginx:latest`
- a container name called `yaml-docker-web`
- a port mapping from local port `8080` to container port `80`
- a restart policy of `unless-stopped`

Use the following structure as orientation, but complete it yourself:

```yaml
services:
  web:
    image: ...
    container_name: ...
    ports:
      - ...
    restart: ...
```

### 2. Start the Compose Project

Run the project with:

```bash
docker compose up -d
```

Open your browser and navigate to:

```text
http://localhost:8080
```

### 3. Inspect the Running Setup

Use the following commands:

```bash
docker compose ps
docker compose logs
docker image ls
docker container ls
```

Add short answers to `docker_notes.md`:

- Which service is running?
- Which image does the service use?
- Which local port is connected to the container?
- Which part of the YAML file controls the port mapping?

### 4. Stop and Clean Up

Stop the Compose project:

```bash
docker compose down
```

Check that the container has been removed:

```bash
docker container ls -a
```

### Final Check

At the end of this exercise, you should be able to explain:

- Why Docker Compose files are written in YAML
- What a service is in a Compose file
- How YAML indentation affects Docker Compose
- How `docker run` and `docker compose up` are related
- How to stop and remove a Compose project

