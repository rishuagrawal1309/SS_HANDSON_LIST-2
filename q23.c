/*
============================================================================
Name : que23
Author : Rishu Agrawal
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21 September, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

int main() {
 
    long max_files = sysconf(_SC_OPEN_MAX);
    if (max_files == -1) {
        perror("sysconf(_SC_OPEN_MAX)");
    } else {
        printf("Maximum number of files a process can open: %ld\n", max_files);
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    long pipe_size = fpathconf(pipefd[0], _PC_PIPE_BUF);
    if (pipe_size == -1) {
        perror("fpathconf(_PC_PIPE_BUF)");
    } else {
        printf("Size of pipe (circular buffer): %ld bytes\n", pipe_size);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
/*
============================================================================
Maximum number of files a process can open: 1048576
Size of pipe (circular buffer): 4096 bytes
============================================================================
*/