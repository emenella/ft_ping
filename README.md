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
- `-R`: Record route. Includes the RECORD_ROUTE option in the ECHO_REQUEST packet and displays the route buffer on returned packets.
- `-d`: Debug mode. Displays additional debug information for each packet, aiding in troubleshooting network issues.
- `-q`: Quiet mode. Suppresses most output, showing only the final results. Useful for discreet testing.

## About the Ping Command
The ping command is a network administration utility used to test the reachability of a host on an Internet Protocol (IP) network. It also measures the round-trip time for the messages sent from the originating host to a destination computer.

# `ping.c` Original Code Summary:

## Definitions and Global Variables:
- `PING_MAXWAIT`: Maximum wait time for a response, in seconds.
- `PING_MAXPACKET`: Maximum packet size.
- `PING_NUMERIC`, `PING_VERBOSE`, `PING_QUIET`, `PING_DEBUG`, `PING_DONTROUTE`, `PING_RROUTE`, `PING_FLOOD`, `PING_CISCO`: Flags for ping options.
- `PING_NROUTES`: Number of slots for route recording option.
- `packet`: Array to store the packet.
- `s`: File descriptor for the socket.
- `whereto`: `sockaddr` structure to define where to send the ping.
- `datalen`: Data size.
- `usage`, `hostname`, `hnamebuf`: Variables related to display and management of hostnames.
- `npackets`, `preload`, `ntransmitted`, `ident`: Variables for tracking statistics.
- `nreceived`, `timing`, `tmin`, `tmax`, `tsum`: Variables for delay statistics.
- `finish()`, `catcher()`, `inet_ntoa()`, `pr_addr()`: Declared but undefined functions.

## Main Functions:
1. **`main(argc, argv)`**: Main function.
   - Parses command line arguments.
   - Configures socket and ping options.
   - Sets the ping destination.
   - Sends pings in a loop.
   - Handles different ping modes (flood, cisco, normal).

2. **`catcher()`**: Handles SIGALRM signals.
   - Sends a new ping and schedules a new SIGALRM signal after 1 second.
   - Handles time offset.

3. **`pinger()`**: Builds and sends an ICMP ECHO REQUEST packet.
   - Fills the packet with data.
   - Calculates ICMP checksum.
   - Sends the packet via the socket.

4. **`pr_pack(buf, cc, from)`**: Displays information about the received packet.
   - Checks IP and ICMP headers.
   - Processes ICMP packet types (ECHO REPLY, UNREACH, etc.).
   - Displays IP options if present.

5. **`finish()`**: Displays ping statistics and terminates the program.
   - Handles display of statistics in flood or normal mode.

## Utility Functions:
- **`in_cksum(addr, len)`**: Calculates ICMP checksum.
- **`tvsub(out, in)`**: Subtracts two `timeval` structures.
- **`pr_icmph(icp)`**: Displays a descriptive string for an ICMP header.
- **`pr_iph(ip)`**: Displays an IP header with its options.
- **`pr_addr(l)`**: Returns a host address in quad-dotted format or with a hostname.
- **`pr_retip(ip)`**: Displays information about an IP packet returned via ICMP.

The code is a simple C program for ping, capable of operating in normal, flood, or cisco mode. It displays detailed statistics on delays and packet loss for a given host.