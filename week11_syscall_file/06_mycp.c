#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char* argv[]){
    if (argc < 3) 
    {
        printf("Usage: %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
        exit(0);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) 
    {
        perror(argv[1]);
        exit(1);
    }

    int num_files = argc - 2;
    int* dest_fd_list = (int*)malloc(sizeof(int) * num_files);
    if (dest_fd_list == NULL) 
    {
        perror("malloc");
        close(src_fd);
        exit(1);
    }

    for (int i = 0; i < num_files; i++)
    {
        const char* dest_name = argv[i + 2];

        int fd = open(dest_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) 
        {
            perror(dest_name);
            dest_fd_list[i] = -1;
        } 
        else {
            dest_fd_list[i] = fd;
        }
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    if (readStr == NULL) 
    {
        perror("malloc");
        close(src_fd);
        free(dest_fd_list);
        exit(1);
    }

    int read_result;
    while(1)
    {
        read_result = read(src_fd, readStr, BUF_SIZE);
        if (read_result < 0) 
        {
            perror("read");
            break;
        }

        if (read_result == 0) 
        {
            // End of File
            break;
        }

        int written = 0;
        while (written < read_result) 
        {
            int n = write(STDOUT_FILENO, readStr + written, read_result - written);
            if (n < 0) 
            {
                perror("write stdout");
                free(readStr);
                free(dest_fd_list);
                close(src_fd);
                exit(1);
            }
            written += n;
        }

        for (int i = 0; i < num_files; i++) 
        {
            if (dest_fd_list[i] == -1) continue; 

            written = 0;
            while (written < read_result) 
            {
                int n = write(dest_fd_list[i], readStr + written, read_result - written);
                if (n < 0) 
                {
                    perror("write dest");
                    free(readStr);
                    free(dest_fd_list);
                    close(src_fd);
                    exit(1);
                }
                written += n;
            }
        }
    }

    close(src_fd);
    for (int i = 0; i < num_files; i++)
    {
        if (dest_fd_list[i] != -1) 
        {
            close(dest_fd_list[i]);
        }
    }

    free(readStr);
    free(dest_fd_list);

    return 0;
}
