#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

//multi thread need errno to avoid a thread disturb another
int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCESS : %s \n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}