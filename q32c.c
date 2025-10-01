/*
============================================================================
Name : que32
Author : Rishu Agrawal
Description : Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 01 October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

void sem_wait(int semid)
{
     struct sembuf sb={0,-1,0}; 
     semop(semid,&sb,1); 
}
void sem_signal(int semid)
{ 
    struct sembuf sb={0,1,0}; 
    semop(semid,&sb,1); 
}

int main(){
    key_t key=ftok("printer",75);

    int semid=semget(key,1,0666|IPC_CREAT);
    semctl(semid,0,SETVAL,2); 

    printf("Process %d waiting..\n",getpid());
    sem_wait(semid);
    printf("Process %d printing..\n",getpid());
    sleep(10); 
    printf("Process %d done.\n",getpid());
    sem_signal(semid);
    return 0;
}

/*
============================================================================
Process 11242 waiting...
Process 11912 waiting...
Process 11242 printing...
Process 11912 printing...
Process 12545 waiting...
Process 11242 done.
Process 12545 printing...
Process 11912 done.
Process 12545 done.

============================================================================
*/