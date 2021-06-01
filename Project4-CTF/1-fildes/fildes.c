#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 100

char buf[MAX_LEN];

int main(int argc, char *argv[]){
	int fd;
	int len;
	setvbuf(stdout, NULL, _IONBF, 0);

    printf("Give me a magic number\n");

	len = read(0, buf, MAX_LEN);

	fd = atoi( buf ) - 0xDEADBEAF;

    printf("OK, then give me a magic string\n");

	len = read(fd, buf, MAX_LEN);

	if(!strncmp("YOUSHALLNOTPASS\n", buf, MAX_LEN)){
		printf("Maybe you learn something :)\n");

		system("/bin/cat flag");
		exit(0);
	}

	printf("Go learn about Linux file IO, and file descriptor\n");
	return 0;
}
