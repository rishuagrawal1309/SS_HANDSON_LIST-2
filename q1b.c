/*
============================================================================
Name : que1a
Author : Rishu Agrawal
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 18 September, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
void handler(int sig)
{
    printf("caught signal %d SIGPROF (profiling timer)\n",sig);
}
int main()
{
    struct itimerval timer;
    signal(SIGPROF, handler);
    timer.it_value.tv_sec=2;
    timer.it_value.tv_usec=0;
    timer.it_interval.tv_sec=10;
    timer.it_interval.tv_usec=1000000;

    setitimer(ITIMER_PROF, &timer, NULL);
    while(1) {}
    return 0;
}

/*
============================================================================
caught signal 27 SIGPROF (profiling timer)
caught signal 27 SIGPROF (profiling timer)
caught signal 27 SIGPROF (profiling timer)
caught signal 27 SIGPROF (profiling timer)
caught signal 27 SIGPROF (profiling timer)
^Z
[4]+  Stopped                 ./a.out
============================================================================
*/

