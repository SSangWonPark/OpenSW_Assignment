#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void){

    for(;;)
    {
        printf("pid: %lu\n", (unsigned long)getpid());
        sleep(1);
    }

    return 0;
}