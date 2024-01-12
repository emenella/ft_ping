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
#define PING_HOST_MAXLEN 64
#define PING_VERBOSE 1
#define PING_RECORD 2
#define PING_DEBUG 4
#define PING_QUIET 8

u_char  packet[PING_MAXPACKET];
int     pingFlags;
int     socket;
hostent *hp;
timezone tz;
int      datalen;
char usage[] = "Todo";
char *hostname;
char hostbuffer[PING_HOST_MAXLEN];

int nreceived = 0;
int timing = 0;
int tmin = 999999999;
int tmax = 0;
int t_sum = 0;

int     finish(), catcher(), pinger();

void    pr_pack(char *buf, void *cc, void *from);