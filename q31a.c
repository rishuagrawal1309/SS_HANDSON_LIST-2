/*
============================================================================
Name : que31
Author : Rishu Agrawal
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 30 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main()
{
    key_t key = 1309;
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    semctl(semid, 0, SETVAL, 1);

    printf("Binary semaphore created with id %d and initialized to 1 \n", semid);
    return 0;
}
/*
============================================================================
Binary semaphore created with id 0 and initialized to 1 
============================================================================
*/