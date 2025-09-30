/*
============================================================================
Name : que31
Author : Rishu Agrawal
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 30 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main()
{
    key_t key = 6543;
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    semctl(semid, 0, SETVAL, 10);

    printf("Counting semaphore created with id %d and initialized to 1 \n", semid);
    return 0;
}
/*
============================================================================
Counting semaphore created with id 1 and initialized to 1 
============================================================================
*/