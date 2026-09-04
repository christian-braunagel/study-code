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


## 🟡 Section III: Create a Dockerfile and Build a First Image

In this exercise, you will create your first own Docker image.
The image will contain a small C++ program that simulates an embedded telemetry check.

### Task Description

Extend the `docker-basics` project folder.
Create a new folder inside it called `embedded-telemetry`.
Inside `embedded-telemetry`, create the following files:

- `main.cpp`
- `Dockerfile`

The goal is to build a Docker image that compiles and runs the C++ program inside a container.

### 1. Create a Small C++ Program

Create `main.cpp`.
The program should print a short status report for an embedded device.

Your program should print the following information:

Example output:

```text
Device: Temperature Control Unit
Firmware: 1.0.0
Temperature: 23.5 C
Voltage: 3.3 V
Status: OK
```

### 2. Create a Dockerfile

Create a `Dockerfile` with the following requirements:

- use a C++ compiler image as the base image
- create a working directory inside the image
- copy `main.cpp` into the image
- compile the program with `g++`
- run the compiled program when the container starts

### 3. Build the Docker Image

Build your image from inside the `embedded-telemetry` folder.

```bash
docker build -t embedded-telemetry:1.0 .
```

After the build, list your local images:

```bash
docker image ls
```

Add short answers to `docker_notes.md`:

- What does the `-t embedded-telemetry:1.0` option do?
- Which base image did Docker download or reuse?
- What is the difference between the Dockerfile and the image?

### 4. Run Your Own Image

Run a container from your image:

```bash
docker run --name telemetry-test embedded-telemetry:1.0
```

Then inspect the container list:

```bash
docker container ls -a
```

Add short answers to `docker_notes.md`:

- What output did your program print?
- Why did the container stop after the program finished?
- Which command in the Dockerfile defines what runs when the container starts?

### 5. Clean Up

Remove the stopped container:

```bash
docker rm telemetry-test
```

Optional: remove the image when you no longer need it:

```bash
docker image rm embedded-telemetry:1.0
```

### Final Check

At the end of this exercise, you should be able to explain:

- What a Dockerfile is
- How a Dockerfile becomes a Docker image
- What the instructions `FROM`, `WORKDIR`, `COPY`, `RUN`, and `CMD` do
- How to build an image with `docker build`
- How to run your own image with `docker run`
