/*
============================================================================
Name : que8f
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
#include<sys/time.h>
void handler(int sig)
{
    printf("caught signal %d SIGVTALRM (virtual timer)\n",sig);
}
int main()
{
    struct itimerval timer;
    signal(SIGVTALRM, handler);
    timer.it_value.tv_sec=2;
    timer.it_value.tv_usec=0;
    timer.it_interval.tv_sec=2;
    timer.it_interval.tv_usec=0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    while(1) {}
    return 0;
}

/*
============================================================================
caught signal 26 SIGVTALRM (virtual timer)
caught signal 26 SIGVTALRM (virtual timer)
caught signal 26 SIGVTALRM (virtual timer)
^Z
[3]+  Stopped                 ./a.out
============================================================================
*/