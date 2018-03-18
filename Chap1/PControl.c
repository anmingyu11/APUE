#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096 /* max line length */

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");

    //ctrl+d fgets return null
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0; /* replace newline with null*/
            //cause execlp need null ending not \n ending
        }

        if ((pid = fork()) < 0)
        {
            printf("fork error\n");
            exit(1);
        }
        else if (pid == 0)
        {
            execlp(buf, buf, (char *)0);
            printf("counldn't execute: %s", buf);
            exit(127);
        }

        //parent
        //ctrl+d is default eof
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            printf("wait pid error ");
            exit(1);
        }
    }
    printf("%%");
}