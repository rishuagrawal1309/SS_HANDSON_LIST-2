/*
============================================================================
Name : que13
Author : Rishu Agrawal
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 20 September, 2025.
============================================================================
*/

//CATCHER
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void handler(int sig)
{
    printf("Caught Signal %d \n",sig);
}
int main()
{
    printf("program 1 pid: %d \n",getpid());
    signal(SIGUSR1, handler);

    while(1)
    {
        pause();
    }
    return 0;
}
/*
============================================================================
Terminal 1: 
program 1 pid: 10819 
Terminal 2:
./q13b 10819
sending SIGUSR! to pif : 10819
Terminal 1:
Caught Signal 10 
============================================================================
*/