/*
============================================================================
Name : que24
Author : Rishu Agrawal
Description : Write a program to create a message queue and print the key and message queue id.
Date: 21 September, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

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

    printf(" Key: %d\n", key);
    printf("Queue ID: %d\n", msgid);

    return 0;
}

/*
============================================================================
Key: 1090929915
Queue ID: 0
============================================================================
*/