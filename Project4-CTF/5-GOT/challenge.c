#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int target;

#define putss(a) write(1, a, strlen(a))

void flag_func(){
    system("/bin/cat flag");
    exit(1);
}

void vuln(){
    char buffer[512];
    putss("Give me some goodies: ");
    //write(1,"Give me some goodies: ", strlen("Give me some goodies: "));
    fgets(buffer, sizeof(buffer), stdin);
    printf(buffer);
    exit(1);
}

int main(int srgc, char **argv){
    putss("Did you see my vuln? Why not try to break me down : )\n");
    vuln();
}
