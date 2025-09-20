/*
============================================================================
Name : que14
Author : Rishu Agrawal
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 20 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
    int fd[2];
    char buf[20];
    pipe(fd);
    write(fd[1], "Hello pipe", 11);
    read(fd[0], buf, 11);
    buf[11]='\0';
    printf("%s \n",buf);

    return 0;
}
/*
============================================================================
Hello Pipe
============================================================================
*/