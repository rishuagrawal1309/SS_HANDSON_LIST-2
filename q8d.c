/*
============================================================================
Name : que8d
Author : Rishu Agrawal
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 18 September, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
void handler(int sig)
{
    printf("caught signal %d SIGALARM \n", sig);
}

int main()
{
    signal(SIGALRM, handler);
    alarm(3);
    pause();    
    return 0;
}

/*
============================================================================
caught signal 14 SIGALARM 
============================================================================
*/