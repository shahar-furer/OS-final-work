#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

void main(int argc, char **argv) {
    if (argc != 3) {
        printf("You have to give scheduler type and priority\n");
        return;
    }

    struct sched_param param;

    param.sched_priority = strtol(argv[2], NULL, 10);
    if (sched_setscheduler(0, strtol(argv[1], NULL, 10), &param)) {
        printf("Failed to set scheduler and priority\n");
        return;
    }

    printf("Done setting the scheduler and the priority\n");
    printf("The process will sleep for 60 seconds and then exit...\n");
    sleep(60);
    return;
}
