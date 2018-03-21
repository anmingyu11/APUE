#include <stdio.h>
// open read write lseek close
// buffersize affect read and write
// Atom operation
// File descriptor
// fd 0 stdin fd 1 stdout fd 2 is stderr
// fd > 0
//STDIN_FILENO  STDOUT_ STDERR in the unistd.h
// a process will open max 63 - 20 early unix use 19
//open char*path int oflag 
//oflag : in <fcntl.h> O_RDONLY
//open  openat return fd is samllest unused fd val
//file name 255 most modern op

// int close(int fd);
// int open(const char *path,intoflat,mode_t mode)
// int opennat(int fd, const char *path,int oflag, mode_t mode)
// int create(const char *path,mode_t mode);
//记录锁
// when a process end kenerl auto close all it's opened file
//current file offset
// O_APPEND unless offset wil be set to 0
int main()
{
    char* path;
}
