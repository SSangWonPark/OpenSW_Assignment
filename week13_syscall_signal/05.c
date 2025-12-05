#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int sig){
    
}

int main(void){
    struct sigaction sa_int;
    sigset_t pending;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sigaddset(&sa_int.sa_mask, SIGINT);
    sa_int.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);
    sigprocmask(SIG_BLOCK, &sa_int.sa_mask, NULL);

    printf("SIGINT blocked. sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n\n");

    sleep(5);

    sigpending(&pending);

    if (sigismember(&pending, SIGINT) == 1) {
        printf("\nSIGINT is pending\n");
    } else {
        printf("\nSIGINT is not pending\n");
    }

    sigprocmask(SIG_UNBLOCK, &sa_int.sa_mask, NULL);

    return 0;
}
