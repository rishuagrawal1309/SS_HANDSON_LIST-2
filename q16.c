/*
============================================================================
Name : que16 
Author : Rishu Agrawal
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 20 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
    int p1[2], p2[2];
    char m1[]="Hello child!!";
    char m2[]="Hello parent!!";
    char buf[100];

    pipe(p1);
    pipe(p2);

    if(fork()==0)
    {
        close(p1[1]);
        close(p2[0]);
        read(p1[0],buf, sizeof(buf));
        printf("child receives : %s \n",buf);
        
        write(p2[1],m2, sizeof(m2));
    }
    else{
        close(p1[0]);
        close(p2[1]);
        write(p1[1],m1,sizeof(m1));
        read(p2[0],buf,sizeof(buf));
        printf("parent receives :%s\n",buf);    
    }
    return 0;
}
/*
============================================================================
child receives : Hello child!! 
parent receives :Hello parent!!
============================================================================
*/