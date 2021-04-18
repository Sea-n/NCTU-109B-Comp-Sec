#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define payload_size 48

int send_pkt(char *payload, char **argv);
unsigned short csum(unsigned short *buf, int nwords);
