FROM archlinux:base-devel-20230723.0.166908

#RUN touch /root/.local/bin/allTests.sh
#RUN echo "bazel query //... | xargs bazel test --test_output=all" >> /root/.local/bin/allTests.sh
#RUN chmod +x /root/.local/bin/allTests.sh

RUN pacman -Syu --noconfirm

# Update the snapshot and install additional tools for development
RUN pacman -S wget git vi --noconfirm

# Messaging library
RUN pacman -S zeromq --noconfirm

RUN pacman -S gtk2 --noconfirm

# Bazelist that is going to be act like a bazel
RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-amd64
RUN chmod +x bazelisk-linux-amd64
RUN mv bazelisk-linux-amd64 /usr/local/bin/bazel

# Openjdk for PlantUML diagram generation
RUN pacman -S jre-openjdk-headless --noconfirm

# C++ to PlantUML (+graphviz for rendering)
RUN pacman -S python-pipx graphviz --noconfirm
RUN pipx install hpp2plantuml
RUN pipx ensurepath                             # add the pipx folder into the PATH
RUN eval "$(register-python-argcomplete pipx)"  # for pipx command completition support

# DOESN'T WORK SINCE IN NON-PRIVILEGED CONTAINER WE DON'T HAVE init AND systemd RUNNING
# Download yay to get access to AUR repos
#RUN wget --no-check-certificate https://repo.arcanis.me/x86_64/yay-12.1.2-1-x86_64.pkg.tar.zst
#RUN pacman -U yay-12.1.2-1-x86_64.pkg.tar.zst --noconfirm

# PlantUML jar
RUN wget https://github.com/plantuml/plantuml/releases/download/v1.2023.10/plantuml-1.2023.10.jar
RUN mv plantuml-1.2023.10.jar /root

# Environment of the root
RUN echo 'alias ll="ls -al"' >> ~/.bashrc

# Create a non-root user with sudo privileges
RUN useradd -m rob && echo 'rob ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# TODO: remove this or the jre20 later
# Additional packages
RUN pacman -S jre8-openjdk --noconfirm
RUN archlinux-java set java-8-openjdk/jre

# Cleanup
RUN rm /var/cache/pacman/pkg/*

USER rob

# Set the working directory to the home directory
WORKDIR /home/rob

RUN echo 'alias ll="ls -al"' >> ~/.bashrc

# TODO: to check if it is really necessary for SVG generation
# Clone and install the fonts -> this will create: ttf-ms-fonts-2.0-12-any.pkg.tar.zst, install it and remove
RUN git clone https://aur.archlinux.org/ttf-ms-fonts.git
RUN cd ttf-ms-fonts && makepkg -si --noconfirm  && cd .. && rm -rf ttf-ms-fonts

USER root
