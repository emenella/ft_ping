FROM debian:buster


CMD ["/bin/bash"]

# Install dependencies
run apt-get update 
RUN apt-get install -y clang vim man gcc clang make iputils-ping tcpdump
RUN mkdir /root/ft_ping

WORKDIR /root/ft_ping