# ft_ping Project

This project is a recoding of the ping command, following specific requirements and guidelines. It aims to test the accessibility of another machine through the IP network and measure the round-trip time for the response.

## Prerequisites
- Docker must be installed on your system to run the project.

## Running the Project
To run the project, execute the following steps:
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Run the `run.sh` script to build and run the project within a Docker container.

### Script: run.sh
The `run.sh` script automates the process of building and running the ft_ping project within a Docker container. It handles the necessary setup and execution steps to ensure a smooth running of the project.

## Options
The ft_ping project includes the following options:
- `-v`: Verbose mode. Displays additional information about the packets sent and received.
- `-c <count>`: Specifies the number of packets to send. The default value is 5.
- `-t <ttl>`: Specifies the time-to-live (TTL) value for the packets sent. The default value is 64.

## About the Ping Command
The ping command is a network administration utility used to test the reachability of a host on an Internet Protocol (IP) network. It also measures the round-trip time for the messages sent from the originating host to a destination computer.