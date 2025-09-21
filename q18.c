/*
============================================================================
Name : que18
Author : Rishu Agrawal
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 20 September, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
int main()
{
   int p1[2];
   int p2[2];
   pipe(p1);
   pipe(p2);

   if(fork()==0)
   {
    close(1);
    dup2(p1[1], STDOUT_FILENO);
    close(p1[0]); close(p1[1]);
    close(p2[0]); close(p2[1]);
    execlp("ls","ls","-l",NULL );
    perror("execlp ls");
    exit(1);

   }
   

    return 0;
}
/*
============================================================================

============================================================================
*/