/*
============================================================================
Name : que15
Author : Rishu Agrawal
Description : Write a simple program to send some data from parent to the child process.
Date: 20 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>

int main()
{
    int fd[2];
    pid_t pid;
    char w[]="Hello!! Rishu here..";
    char r[100];
    if(pipe(fd)==-1)
    {
        perror("pipe");
        exit(1);
    }
    pid=fork();
    if(pid<0)
    {
        perror("fork");
        exit(1);
    }
    
    if(pid>0)
    {
        close(fd[0]);
        write(fd[1], w, strlen(w)+1);
        close(fd[1]);
        printf("parent send : %s \n",w);
    }
    else{
        close(fd[1]);
        read(fd[0],r,sizeof(r));
        printf("child received : %s \n",r);
        close(fd[0]);
    }
    return 0;

}
/*
============================================================================
parent send : Hello!! Rishu here.. 
child received : Hello!! Rishu here.. 
============================================================================
*/