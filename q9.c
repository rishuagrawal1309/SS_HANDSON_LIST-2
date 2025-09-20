/*
============================================================================
Name : que9
Author : Rishu Agrawal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 18 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
    printf("ignoring SIGINT (pressing ctrl+c won't terminate it).\n");
    signal(SIGINT, SIG_IGN);
    for(int i=0;i<5;i++)
    {
        printf("running.. SIGINT ignored successfully. \n");
        sleep(1);
    }
    printf("resetting deafult  action \n");
    signal(SIGINT, SIG_DFL);
    printf("now pressing ctrl+c will terminate. \n");
    while(1)
    {
        printf("running... try ctrl+c \n");
        sleep(2);
    }

    return 0;
}

/*
============================================================================
ignoring SIGINT (pressing ctrl+c won't terminate it).
running.. SIGINT ignored successfully. 
running.. SIGINT ignored successfully. 
running.. SIGINT ignored successfully. 
^C
running.. SIGINT ignored successfully. 
running.. SIGINT ignored successfully. 
^C
resetting deafult  action 
now pressing ctrl+c will terminate. 
running... try ctrl+c 
^C
============================================================================
*/