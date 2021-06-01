#include <stdio.h>
#include <stdlib.h>

void payload_test(char* in){
    for(char c = *in++; c != '\x00'; c = *in++) {
        if(c=='A') {
            printf("Hey, don't hacked me! Be wiser next time : >\n");
            exit(-1);
        }
    }
}

void verify() {
    char buf[256] = {0};
    printf("Wanna get my secret? Come and get it with your payload <3\n");
    gets(buf);
    payload_test(buf);
    printf(buf);
}

int main(int argc, char* argv[]) {
    while(1) {
        verify();
    }
}

