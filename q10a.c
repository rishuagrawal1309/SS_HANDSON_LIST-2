/*
============================================================================
Name : que10a
Author : Rishu Agrawal
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 18 September, 2025.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
void handler(int sig)
{
  printf("Caught signal %d \n", sig);
  exit(1);
}
int main()
{
    signal(SIGSEGV, handler);
    int *p=NULL;
    *p=10;
    return 0;
}

/*
============================================================================
Caught signal 11 
============================================================================
*/