#include "utils.h"

unsigned short in_cksum(struct icmp *message, int len)
{
    unsigned short *data = (unsigned short*) message;
    long sum = 0;

    while (len > 1)
    {
        sum += *data++;
        if (sum & 0x80000000)
            sum = (sum & 0xFFFF) + (sum >> 16);
        len -= 2;
    }
    if (len)
        sum += *data;
    while(sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    return ~sum;
}