/*
============================================================================
Name : que27 a
Author : Rishu Agrawal
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 30 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg 
{
    long type;
    char text[100];
};

int main()
{
    key_t key = ftok("msgqueuefile", 65);
    int msgid = msgget(key, 0666);

    struct msg m;

    msgrcv(msgid, &m, sizeof(m.text), 1, 0);
    printf("Received in blocking mode : %s \n", m.text);

    return 0;
}
/*
============================================================================
Received in blocking mode : rishuuuu 
============================================================================
*/