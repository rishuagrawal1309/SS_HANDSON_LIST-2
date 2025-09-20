/*
============================================================================
Name : que8b
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
#include<stdlib.h>
#include<signal.h>
void handler(int sig)
{
   printf("\n caughht signal %d \n", sig);
   exit(0);
}
int main()
{
    signal(SIGINT, handler);
    while(1)
    {
        printf("Running.. press ctrl+c to send SIGNINT \n");
        sleep(2);
    }
    return 0;
}

/*
============================================================================
Running.. press ctrl+c to send SIGNINT 
Running.. press ctrl+c to send SIGNINT 
^C
caughht signal 2 
============================================================================
*/