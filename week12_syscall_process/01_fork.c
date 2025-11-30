#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void){
    pid_t chile_pid;

    chile_pid = fork();
    if (chile_pid == 0)
    {   // child process
        printf("Child process PID: %lu\n Child process PPID: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
        return 7;
    }
    else 
    {   // parent process
        int wstatus;
        waitpid(chile_pid, &wstatus, 0);
        if (WIFEXITED(wstatus))
        {
            printf("Child exited with status: %d\n", (int)WEXITSTATUS(wstatus));
        }

        printf("Parent process PID: %lu\n Parent process PID: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
    }

    return 0;
}