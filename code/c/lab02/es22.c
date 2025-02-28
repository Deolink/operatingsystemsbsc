#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "utils.h"

int main(int argc, char **argv) {
    pid_t pid;
    
    pid = fork();
    switch (pid) {
        case -1: /* error */
            zprintf(2, "error: fork()\n");
            exit(EXIT_FAILURE);
        case 0: /* child */
            zprintf(1, "[%d] Hello, I'm the child! [fork()=%d]\n", getpid(), pid);
            exit(EXIT_SUCCESS);
    }

    /* father */
    zprintf(1, "[%d] Hello, I'm the father! [fork()=%d]\n", getpid(), pid);
    wait_child();
    exit(EXIT_SUCCESS);
}


