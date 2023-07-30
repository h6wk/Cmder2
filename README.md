# Developer environment

Install:
* Docker
* Visual Studio Code & Extensions
  * *Remote Development* (v0.24.0). The package will inculde the *Dev Containers* extension.

Start the docker service on your workstation. Clone this github repository and start VS Code. Press CTRL-SHIFT-p and search for *Dev container: New dev container* and/or *Dev container: Rebuild Container* (*Dev container: Clone repository in container volume...*). It will use the **devcontainer.json** and **Dockerfile** to build a new Arch Linux developer environment (or rebuild and existing one).
