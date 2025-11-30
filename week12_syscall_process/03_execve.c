#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;   

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <program path> [OPTION]...\n", argv[0]);
    }

    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        // Child process
        if (argc < 2) {
            return 0;
        }

        int num_args = argc - 1;
        char **child_argv = malloc(sizeof(char*) * (num_args + 1));
        if (!child_argv) 
        {
            return 1;
        }

        for (int i = 0; i < num_args; i++)
        {
            child_argv[i] = argv[i + 1];
        }
        child_argv[num_args] = NULL;

        execve(argv[1], child_argv, environ);
        perror("execve");
        free(child_argv);
        return 1;
    }

    else {
        // Parent process
        int wstatus;
        waitpid(child_pid, &wstatus, 0);

        if (WIFEXITED(wstatus)) {
            printf("Child exited with status: %d\n",
                   WEXITSTATUS(wstatus));
        }
    }

    return 0;
}
