#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("pid : %ld", (long)getpid());
    exit(0);
}