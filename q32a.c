/*
============================================================================
Name : que32
Author : Rishu Agrawal
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 01 October, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>
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
    key_t key = ftok("ticket", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 1);
    sem_wait(semid);

    int fd  = open("ticket.txt", O_RDWR|O_CREAT, 0644);
    int t =0;
    read(fd, &t, sizeof(t));
    lseek(fd, 0, SEEK_SET);
    t++;
    write(fd, &t, sizeof(t));
    printf("Ticket created : %d \n",t);
    close(fd);

    sem_signal(semid);
    return 0;
}
/*
============================================================================
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q32a.c
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Ticket created : 1 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Ticket created : 2 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Ticket created : 3 
============================================================================
*/