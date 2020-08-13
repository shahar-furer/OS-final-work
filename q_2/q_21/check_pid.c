#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

void main(int argc, char **argv) {
    if (argc != 2) {
        printf("You have to give pid\n");
        return;
    }

    int pid = strtol(argv[1], NULL, 10);
    if (kill(pid, 0)) {
        if (errno == EPERM) {
            printf("Process %d exists but we have no permission.\n", pid);
        }
        else if (errno == ESRCH) {
            printf("Process %d does not exist.\n", pid);
        }
    } else {
        printf("Process %d exists.\n", pid);
    }

    return;
}
