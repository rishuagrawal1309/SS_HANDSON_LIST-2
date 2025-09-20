/*
============================================================================
Name : que11
Author : Rishu Agrawal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 20 September, 2025.
============================================================================
*/

#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
  signal(SIGINT, SIG_IGN);
  printf("SIGINT is ignored for 10 sec. press ctrl-c.\n");
  sleep(10);

  signal(SIGINT, SIG_DFL);
  printf("\n SIGINT default action restored. press ctrl-c to terminate.\n");

  while(1)
  {
    pause();
  }
  
 return 0;
}    

/*
============================================================================
SIGINT is ignored for 10 sec. press ctrl-c.
^C
SIGINT default action restored. press ctrl-c to terminate.
^C
============================================================================
*/