FROM archlinux:base-devel-20230723.0.166908

# Update the snapshot and install additional tools for development
RUN pacman -Syu --noconfirm && \
  pacman -S wget git vi --noconfirm

# Bazelist that is going to be act like a bazel
RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-amd64
RUN chmod +x bazelisk-linux-amd64
RUN mv bazelisk-linux-amd64 /usr/local/bin/bazel

# Openjdk for PlantUML diagram generation
RUN pacman -S jre-openjdk-headless --noconfirm

# C++ to PlantUML
RUN pacman -S python-pipx --noconfirm
RUN pipx install hpp2plantuml
RUN pipx ensurepath                             # add the pipx folder into the PATH
RUN eval "$(register-python-argcomplete pipx)"  # for pipx command completition support
