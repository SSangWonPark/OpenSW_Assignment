#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]) {

    if (argc != 1) 
    {
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);

    int read_result;

    while (1) 
    {
        read_result = read(STDIN_FILENO, readStr, BUF_SIZE);

        if (read_result < 0) 
        {
            perror("read");
            free(readStr);
            exit(1);
        }

        if (read_result == 0) 
        {
            printf("Detected EOF (Ctrl + D)\n");
            printf("Terminating read loop...\n");
            break;
        }

        int written = write(STDOUT_FILENO, readStr, read_result);
        if (written < 0) 
        {
            perror("write");
            free(readStr);
            exit(1);
        }
    }

    free(readStr);
    return 0;
}
