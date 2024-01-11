#include <stdio.h>
#include <errno.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <sys/param.h>
#include <sys/file.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/in_systm.h>
#include <netdb.h>

#define PING_MAXWAIT 10
#define PING_MAXPACKET 4096
#define PING_VERBOSE 1
#define PING_RECORD 2
#define PING_DEBUG 4
#define PING_QUIET 8
