/*
============================================================================
Name : que28
Author : Rishu Agrawal
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);
    buf.msg_perm.mode= 0644;
     printf("permission changed to %o\n", buf.msg_perm.mode);
     return 0;
}
/*
============================================================================
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q28.c
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
permission changed to 644
============================================================================
*/