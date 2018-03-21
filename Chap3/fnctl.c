#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int val;

    if (argc != 2)
    {
        printf("usage : fcntl <descriptor#>");
        exit(1);
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        printf("fcntl error for fd %d", atoi(argv[1]));
    }

    switch (val & O_ACCMODE)
    {
        case O_RDONLY:
        {
            printf("read only");
            break;
        }
        case O_WRONLY:
        {
            printf("write only");
            break;
        }
        case O_RDWR:
        {
            printf("read write");
            break;
        }
        default:{
            printf("unknown access mode");
        }
    }
}