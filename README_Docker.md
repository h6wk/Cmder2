# Docker

The __Dockerfile__ is used to set up a linux developer environment for the project. Install docker package on Linux or Docker Desktop on Windows Docker Desktop that enables you to build and share containerized applications and microservices. Run the commands to get the image and start a container of it:

```console
$ docker build -t  IMAGENAME .
```

```console
$ docker run -d -p 2222:22 --security-opt seccomp:unconfined -v .:/source --name IMAGENAME
```

# Base image

Base image: __archlinux__


# Additional packages

Packages:
* g++, gdb, build-essentials
* git
* openssh-server
* wget

Additional binaries:
* Bazelisk 1.17 copied into /usr/local/bin/bazel

The __Dockerfile__ downloads and installs the __bazelisk__ to the Debian image. The bazel build environment is defined by the configuration files checked in the GIT repository. More detail about the bazel: [here](README_Bazel.md).