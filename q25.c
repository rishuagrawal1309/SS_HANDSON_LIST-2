/*
============================================================================
Name : que25
Author : Rishu Agrawal
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 21 September, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok("msgqueuefile", 65); 
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message Queue ID: %d\n", msgid);
    printf("Access Permissions: %o\n", buf.msg_perm.mode & 0777);
    printf("Owner UID: %d\n", buf.msg_perm.uid);
    printf("Owner GID: %d\n", buf.msg_perm.gid);
    printf("Creator UID: %d\n", buf.msg_perm.cuid);
    printf("Creator GID: %d\n", buf.msg_perm.cgid);
    printf("Time of last message sent: %s", ctime(&buf.msg_stime));
    printf("Time of last message received: %s", ctime(&buf.msg_rtime));
    printf("Time of last change in message queue: %s", ctime(&buf.msg_ctime));
    printf("Current size of queue in bytes: %ld\n", buf.__msg_cbytes);
    printf("Number of messages in queue: %ld\n", buf.msg_qnum);
    printf("Maximum bytes allowed in queue: %ld\n", buf.msg_qbytes);
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
============================================================================
Message Queue ID: 0
Access Permissions: 666
Owner UID: 1000
Owner GID: 1000
Creator UID: 1000
Creator GID: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change in message queue: Sun Sep 21 16:51:35 2025
Current size of queue in bytes: 0
Number of messages in queue: 0
Maximum bytes allowed in queue: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
============================================================================
*/