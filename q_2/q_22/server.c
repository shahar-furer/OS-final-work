#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int sigusr1 = 0;
int sigint = 0;

void handler_for_usr1(int sig) {
    if (sig == SIGUSR1) {
        sigusr1++;
    }
}

void handler_for_int(int sig) {
    if (sig == SIGINT) {
        sigint++;
    }
}

void main(int argc, char **argv) {
    if (signal(SIGUSR1, handler_for_usr1)) {
        printf("Failed to set handler for SIGUSR1\n");
        return;
    }
    if (signal(SIGINT, handler_for_int)) {
        printf("Failed to set handler for SIGINT\n");
        return;
    }
    printf("The server will wait to receive signals, press any key to stop it\n");
    getc(stdin);
    printf("%d signals of type SIGUSR1 were sent\n", sigusr1);
    printf("%d signals of type SIGINT were sent\n", sigint);
    return;
}
