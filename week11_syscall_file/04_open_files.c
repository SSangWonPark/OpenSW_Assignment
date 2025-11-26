#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: %s [file1 file2 ...]\n", argv[0]);
        return 1;
    }

    int num_files = argc - 1;
    int *fd_list = (int *)malloc(sizeof(int) * num_files);

    if (fd_list == NULL) 
    {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < num_files; i++) 
    {
        const char *filename = argv[i + 1];

        int fd = open(filename, O_RDONLY);

        if (fd == -1) 
        {
            perror(filename);
            fd_list[i] = -1;
        } 
        else {
            printf("Opened successfully: %s (fd = %d)\n", filename, fd);
            fd_list[i] = fd;
        }
    }

    for (int i = 0; i < num_files; i++) 
    {
        if (fd_list[i] != -1) 
        {
            if (close(fd_list[i]) == -1) 
            {
                perror("close");
            } 
            else {
                printf("Closed successfully: %s\n", argv[i + 1]);
            }
        }
    }

    free(fd_list);
    return 0;
}
