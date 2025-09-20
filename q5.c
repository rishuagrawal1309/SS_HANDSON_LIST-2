/*
============================================================================
Name : que5
Author : Rishu Agrawal
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 18 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    long val;
    val = sysconf(_SC_ARG_MAX);
    if(val==-1)
    perror("max length of arg cannot find \n");
    else 
    printf("max length of  arguments : %ld \n",val);

    val = sysconf(_SC_CHILD_MAX);
    if(val==-1)
    perror("maxx simultaneous process cannot find \n");
    else 
    printf("max simultaneous process per user id ; %ld \n", val);

    val=sysconf(_SC_CLK_TCK);
    if(val==-1)
    perror("clock not find \n");
    else
    printf("clock ticks per second : %ld \n",val);

    val= sysconf(_SC_OPEN_MAX);
    if(val==-1)
    perror("max open file no find \n");
    else
    printf("max open files per process: %ld \n",val);

    val=sysconf(_SC_PAGESIZE);
    if(val==-1)
    perror("size of page not find \n");
    else
    printf("size of page in bytes :%ld \n",val);

    
    val=sysconf(_SC_AVPHYS_PAGES);
    if(val==-1)
    perror("available physical memory page not defined \n");
    else
    printf("no. of currently available pages in physical memory :%ld \n",val);
    return 0;


}

/*
============================================================================
max length of  arguments : 2097152 
max simultaneous process per user id ; 30145 
clock ticks per second : 100 
max open files per process: 1048576 
size of page in bytes :4096 
no. of currently available pages in physical memory :165203
============================================================================
*/