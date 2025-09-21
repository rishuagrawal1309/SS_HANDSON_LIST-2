/*
============================================================================
Name : que17
Author : Rishu Agrawal
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 20 September, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int fd[2]; pipe(fd);

    if (fork() == 0) {              
        close(1);                   
        dup(fd[1]);                 
        close(fd[0]); close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    if (fork() == 0) {              
        close(0);                   
        dup(fd[0]);                 
        close(fd[0]); close(fd[1]);
        execlp("wc", "wc", NULL);
        exit(1);
    }
    close(fd[0]); close(fd[1]);
    wait(NULL); wait(NULL);
    return 0;
}

/*
============================================================================
 34     299    1725
============================================================================
*/