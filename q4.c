/*
============================================================================
Name : que4
Author : Rishu Agrawal
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 18 September, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

unsigned long long rdtsc()
{
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main()
{
    unsigned long long start, end;
    int i;
    start = rdtsc();
    for(int i=0;i<100;i++)
    {
        getppid();
    }
    end = rdtsc();
    printf("total cpu cycles : %llu \n", start-end);
    printf("\n");
    return 0;
}

/*
============================================================================
total cpu cycles : 18446744073709364324 
============================================================================
*/