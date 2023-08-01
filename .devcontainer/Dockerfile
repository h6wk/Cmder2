FROM archlinux:base-devel-20230723.0.166908

# Update the snapshot and install additional tools for development
RUN pacman -Syu --noconfirm && \
  pacman -S wget git vi --noconfirm

# Bazelist that is going to be act like a bazel
RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-amd64
RUN chmod +x bazelisk-linux-amd64
RUN mv bazelisk-linux-amd64 /usr/local/bin/bazel

# Openjdk 20 for PlantUML diagram generation
RUN pacman -S jre-openjdk-headless --noconfirm
