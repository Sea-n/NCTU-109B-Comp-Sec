#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win(){
    system("/bin/cat flag");
}

int main(int argc, char **argv){
    volatile int (*fp)();
    char input[64];

    fp = 0;
    
    printf("Hey! Do you know how to telesport? Try to put a spell!\n");
    printf("Your spell: ");
    fflush(stdout);
    gets(input);

    if(fp){
        printf("Teleportation Starting....\nJumping to 0x%08x\n", fp);
        fp();
    }
    else{
        printf("Na~sorry, that wizardry didn't work!\n");
    }
}
