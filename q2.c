/*
============================================================================
Name : que2
Author : Rishu Agrawal
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 18 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<unistd.h>

void print_limit(int resource, const char *name)
{
    struct rlimit lim;
    if(getrlimit(resource, &lim)==0)
    {
        printf("%s", name);
    
    if(lim.rlim_cur == RLIM_INFINITY)
    {
        printf("soft limit unlimited \n");
    }
    else printf("soft limit= %ld \n", (long)lim.rlim_cur);
    if(lim.rlim_max==RLIM_INFINITY)
    {
        printf("hard limit unlimited \n");
    }
    else printf("hard limit= %ld \n",(long)lim.rlim_max);
   }
   else perror("getrlimit \n");
   printf("\n");
}
int main()
{
    printf("system resource limit - \n");
    print_limit(RLIMIT_CPU, "cpu time ");
    print_limit(RLIMIT_FSIZE,"file size max");
    print_limit(RLIMIT_DATA,"Data segment size");
    print_limit(RLIMIT_AS,"address space");
    print_limit(RLIMIT_NOFILE,"open files");
    print_limit(RLIMIT_MEMLOCK,"locked memory in bytes");

    return 0;
}

/*
============================================================================
system resource limit - 
cpu time soft limit unlimited 
hard limit unlimited 

file size maxsoft limit unlimited 
hard limit unlimited 

Data segment sizesoft limit unlimited 
hard limit unlimited 

address spacesoft limit unlimited 
hard limit unlimited 

open filessoft limit= 1048576 
hard limit= 1048576 

locked memory in bytessoft limit= 1007104000 
hard limit= 1007104000
============================================================================
*/