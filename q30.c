/*
============================================================================
Name : que30
Author : Rishu Agrawal
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 30 September, 2025.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>
#include<setjmp.h>
#include<string.h>

jmp_buf buf;

void sigsegv_handler(int sig)
{
  printf("!!Cannot write to read-only shared memory. \n");
  longjmp(buf,1);
}

int main()
{
  key_t key = ftok("shmfile", 65);
  int shmid= shmget(key, 1024, 0666 | IPC_CREAT);
  char input[1024];
  char *data = (char*) shmat(shmid,NULL,0);
  
  printf("enter message to store in shared memory : ");
  
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")]=0;
  
  strcpy(data,input);
  
  printf("data written : %s \n", data);  
  
  shmdt(data);

  data = (char *)shmat(shmid, NULL, SHM_RDONLY);
  printf("Data read (read only attached) : %s \n", data);
  
  printf("Enter message to overwrite in read only shared memory: ");
  
  char attempt[1024];
  
  fgets(attempt, sizeof(attempt), stdin);
  attempt[strcspn(attempt, "\n")]=0;

  signal(SIGSEGV, sigsegv_handler);
  if(setjmp(buf)==0)
  {
    printf("Attempt to overwrie read only shared mem.. \n");
    strcpy(data, attempt);
    printf("overwrite successful unexpectedly \n");
  }
  else{
    printf("overwrite prevented safely \n");
  }

  shmdt(data);
  
  shmctl(shmid, IPC_RMID, NULL);
  
  printf("shared memory removed successfully. \n");
  return 0;
}
/*
============================================================================
enter message to store in shared memory : Hello Rishu!!
data written : Hello Rishu!! 
Data read (read only attached) : Hello Rishu!! 
Enter message to overwrite in read only shared memory: Rishu is learning Shared Memory
Attempt to overwrie read only shared mem.. 
!!Cannot write to read-only shared memory. 
overwrite prevented safely 
shared memory removed successfully. 
============================================================================
*/