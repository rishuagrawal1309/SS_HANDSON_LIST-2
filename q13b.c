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

//SENDER
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Usage: %s <PID> \n",argv[0]);
        return 1;
    }
    pid_t pid = atoi(argv[1]);
    printf("sending SIGUSR! to pif : %d\n",pid);

    kill(pid,SIGUSR1);
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