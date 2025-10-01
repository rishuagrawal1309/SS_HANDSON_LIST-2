/*
============================================================================
Name : que32
Author : Rishu Agrawal
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 01 October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main() {
    key_t key = ftok("semfile", 65);             
    int semid = semget(key, 1, 0666 | IPC_CREAT); 
    semctl(semid, 0, SETVAL, 1);           

    struct sembuf p = {0, -1, 0}; 
    struct sembuf v = {0, 1, 0};  

    printf("Process %d entering critical section...\n", getpid());
    semop(semid, &p, 1); 

    printf("Process %d is working...\n", getpid());
    sleep(2);

    printf("Process %d leaving critical section...\n", getpid());
    semop(semid, &v, 1); 

    semctl(semid, 0, IPC_RMID);
    printf("Semaphore removed.\n");

    return 0;
}

/*
============================================================================
Process 12942 entering critical section...
Process 12942 is working...
Process 12942 leaving critical section...
Semaphore removed.
============================================================================
*/