#include <unistd.h>
#include <stdio.h>

int main(){
    printf("pid: %lu\n", (unsigned long)getpid());
    printf("ppid: %lu\n", (unsigned long)getppid());

    return 0;
}