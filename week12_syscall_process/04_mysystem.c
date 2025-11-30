#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int mysystem(char *cmd){
    pid_t chile_pid;

    chile_pid = fork();
    if (chile_pid == 0)
    {   // child process
        execl("/bin/sh", "sh", "-c", cmd, (char *) NULL);
        return 100;
    }
}

int main(void){
    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");
    
    printf("Good bye~\n");

    return 0;
}