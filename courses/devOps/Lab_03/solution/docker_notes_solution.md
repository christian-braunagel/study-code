# Docker Notes

## First Container

When `docker run hello-world` is executed, Docker checks whether the `hello-world` image is available locally.
If the image is not available, Docker downloads it from Docker Hub and starts a container from it.

An image is a reusable template for a container.
A container is a running or stopped instance created from an image.

## Images and Containers

`docker image ls` shows images that are stored locally.
`docker container ls` shows only running containers.
`docker container ls -a` also shows stopped containers.

## Interactive Ubuntu Container

The command `docker run -it ubuntu bash` starts an Ubuntu container with an interactive shell.
Inside the container, `/etc/os-release` shows information about the Ubuntu operating system.
Typing `exit` stops the shell process, so the container stops.

Interactive containers are useful for testing tools, exploring environments, and checking behavior without changing the host system.

## Web Server Container

The option `-p 8080:80` maps port `8080` on the local machine to port `80` inside the container.
The option `-d` starts the container in detached mode, so it runs in the background.

Stopped containers should be removed when they are no longer needed because they can make the Docker environment harder to inspect and maintain.

## Docker Compose

The Compose service `web` uses the image `nginx:latest`.
The local port `8080` is connected to container port `80`.
This is controlled by the `ports` section in `compose.yaml`.

Docker Compose files are written in YAML because YAML is readable and supports nested configuration structures.
The `services` section describes the containers that belong to the application.
