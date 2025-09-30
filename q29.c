/*
============================================================================
Name : que29
Author : Rishu Agrawal
Description : Write a program to remove the message queue.
Date: 30 September, 2025.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
int main()
{
    key_t key = ftok("msgqueuefile", 65);
    int msgid = msgget(key, 0666);
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message queue with id %d removed successfully. \n",msgid);
    return 0;
}


/*
============================================================================
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q29.c
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Message queue with id 0 removed successfully
============================================================================
*/