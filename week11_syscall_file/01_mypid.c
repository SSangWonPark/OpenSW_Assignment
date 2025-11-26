#include <unistd.h>
#include <stdio.h>

int main(){
    printf("pid: %lu\n", (unsigned long)getpid());

    return 0;
}