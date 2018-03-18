#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main(void)
{
    int n;
    char buf[BUFFSIZE];

    //open, read, write, lseek close unblock I/O
    //this two macro is posic std
    // diff buffsize will affect performance
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        //read return reading byte size
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("write error\n");
            exit(1);
        }
    }

    if (n < 0)
    {
        printf("read error");
    }
    exit(0);
}