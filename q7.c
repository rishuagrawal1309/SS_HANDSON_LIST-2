/*
============================================================================
Name : que7
Author : Rishu Agrawal
Description : Write a simple program to print the created thread ids.
Date: 18 September, 2025.
============================================================================
*/
#include<pthread.h>
#include<stdio.h>

void* thread(void* a)
{
  int id= *(int *)a;
  printf("Hello!! I am from thread %d. \n",id);
  return NULL;
}
int main()
{
    pthread_t p[3];
    int id[3]={101,202,303};

    for(int i=0;i<3;i++)
    {
        pthread_create(&p[i], NULL, thread, &p[i]);
    }
    for(int i=0;i<3;i++)
    {
      pthread_join(p[i],NULL);
    }

    printf("Hello!! This is from main thread. \n");
    return 0;
}

/*
============================================================================
Hello!! I am from thread 12580544. 
Hello!! I am from thread -67111232. 
Hello!! I am from thread -75503936. 
Hello!! This is from main thread.
============================================================================
*/