/*
============================================================================
Name : que3
Author : Rishu Agrawal
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 18 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>

void print_limit(int resource, const char* name)
{
  struct rlimit lim;
  if(getrlimit(resource, &lim)==0)
  {
    printf("%s: \n",name);
    if(lim.rlim_cur==RLIM_INFINITY)
    printf("soft imit unlimited \n");
    else 
    printf("soft=%ld\n",(long)lim.rlim_cur);
    if(lim.rlim_max==RLIM_INFINITY)
    printf("hard link unlimited \n");
    else 
    printf("hard= %ld \n",(long)lim.rlim_max);

  }
  else perror("getrlimit \n");
}
int main()
{
    struct rlimit lim;
    printf("BEFORE CHANGING LIMITS: \n");
    print_limit(RLIMIT_CORE,"core file size ");

    lim.rlim_cur=0;
    lim.rlim_max=0;
    if(setrlimit(RLIMIT_CORE, &lim)!=0)
    {
        perror("setrlimit \n");
        exit(1);
    }
    printf("AFTER CHANGING LIMTIS: \n");
    print_limit(RLIMIT_CORE, "core file size");

    return 0;
}

/*
============================================================================
BEFORE CHANGING LIMITS: 
core file size : 
soft=0
hard link unlimited 
AFTER CHANGING LIMTIS: 
core file size: 
soft=0
hard= 0 
============================================================================
*/
