FROM archlinux:base-devel-20230723.0.166908

RUN pacman -Syu --noconfirm && \
  pacman -S wget git vi --noconfirm

RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-amd64
RUN chmod +x bazelisk-linux-amd64
RUN mv bazelisk-linux-amd64 /usr/local/bin/bazel
