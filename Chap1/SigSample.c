#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#define MAXLINE 4096 /* max line length */

static void sig_int(int);
//signal用于通知进程发生了某种情况
//SIGFPE
//Key Singnal ctrl+c 中断键 ctrl+\退出键,他们备用与中断当前运行的进程
//func kill canbe called by other process must be owner of process or super user
int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        printf("signal error");
    }

    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0)
        {
            printf("fork error");
            exit(1);
        }
        else if (pid == 0)
        {
            //child
            execlp(buf, buf, (char *)0);
            printf("couln't execute %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            printf("waitpid error");
            exit(1);
        }
    }

    exit(0);
}

void sig_int(int signo)
{
    printf("interruptting...............\n");
}