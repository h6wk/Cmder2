# Developer environment

Install:
* Docker
* Visual Studio Code & Extensions
  * *Remote Development* (v0.24.0) - The package inculdes the *Dev Containers* extension.
  * *C/C++ Extension Pack* (v1.3.0) - The package incudes Intellisense that will help the C++ development.
  * *C/C++ Include Guard* (v1.7.1)
  * *PlantUML* (v2.17.5)

Start the docker service on your workstation. Clone this github repository and start VS Code. Press CTRL-SHIFT-p and search for *Dev container: New dev container* and/or *Dev container: Rebuild Container* (*Dev container: Clone repository in container volume...*). It will use the **devcontainer.json** and **Dockerfile** to build a new Arch Linux developer environment (or rebuild and existing one).
