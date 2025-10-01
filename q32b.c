/*
============================================================================
Name : que32
Author : Rishu Agrawal
Description : Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
Date: 01 October, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>

void sem_wait(int semid)
{
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1);
}

void sem_signal(int semid)
{
    struct sembuf sb = {0,1,0};
    semop(semid, &sb, 1);
}

int main()
{

    key_t key = ftok("shmfile",65);
    int shmid = shmget(key, 1024, 0666 |IPC_CREAT);
    char *str = (char*)shmat(shmid,NULL,0);

    int semid = semget(key, 1, 0666|IPC_CREAT);
    semctl(semid, 0, SETVAL, 1);

    sem_wait(semid);
    printf("Enter message : ");
    fgets(str,1024,stdin);
    printf("Received text : %s \n",str);
    sem_signal(semid);

    shmdt(str);
    return 0;
}
/*
============================================================================
TERMINAL 1 :-

lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q32b.c
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Enter message : hellooo
Received text : hellooo

lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0xffffffff 2          lenovo     666        1024       0                       

TERMINAL 2 :- 

Enter message : hyy
Received text : hyy
 

============================================================================
*/