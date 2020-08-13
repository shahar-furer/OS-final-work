#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char **argv) {
    if (argc != 4) {
        printf("You have to give: pid of the server, kind of signal and how many signals you want to send\n");
        return;
    }

    int pid = strtol(argv[1], NULL, 10);
    int signal_to_send = strtol(argv[2], NULL, 10);
    int signal_count = strtol(argv[3], NULL, 10);

    while(signal_count > 0) {
        if (kill(pid, signal_to_send)) {
            printf("Kill Failed to send signal!\n");
        } else {
            printf("Kill succeeded to send signal!\n"); 
        }
        signal_count--;
    }

    return;
}
