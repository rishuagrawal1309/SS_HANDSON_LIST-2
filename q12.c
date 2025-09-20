/*
============================================================================
Name : que12
Author : Rishu Agrawal
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 20 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
int main()
{
  pid_t pid=fork();
  if(pid<0)
  {
    perror("fork fail.");
    exit(1);
  }
  else if(pid==0)
  {
    printf("child pid : %d, parents pid : %d \n", getpid(), getppid());
    kill(getppid(), SIGKILL);
    printf("parent process killed. new ppid = %d \n",getppid());
    sleep(2);
  }
  else{
    while(1)
    {
        printf("pid: %d \n",getpid());
        sleep(1);
    }
  }
  return 0;
    
}
/*
============================================================================
pid: 9694 
child pid : 9695, parents pid : 9694 
parent process killed. new ppid = 9694 
Killed
============================================================================
*/