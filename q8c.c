/*
============================================================================
Name : que10c
Author : Rishu Agrawal
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 18 September, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void handler(int sig)
{
    printf("caught signal %d SIGFPE \n", sig);
    exit(1);
}

int main()
{
    signal(SIGFPE, handler);
    int x=4, y=0;
    int z=x/y;
    printf("%d \n",z);
    return 0;
}

/*
============================================================================
caught signal 8 SIGFPE
============================================================================
*/