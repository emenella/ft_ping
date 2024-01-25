#include <netinet/ip_icmp.h>
#include <sys/time.h>

unsigned short      in_cksum(struct icmp *message, int len);
void                tvsub(struct timeval *out, struct timeval *in);
void                pr_icmph(void *icp);
void                pr_iph(void *ip);
void                pr_addr(void *l);
void                pr_retip(void *ip);