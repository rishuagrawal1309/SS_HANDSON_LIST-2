/*
============================================================================
Name : que19(d)
Author : Rishu Agrawal
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 21 September, 2025.
============================================================================
*/
#define _XOPEN_SOURCE 700  
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>   

int main() {
    const char *fifo_name = "fifo_mkfifo_c";

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    printf("FIFO '%s' created using mkfifo() library function.\n", fifo_name);
    return 0;
}

/*
============================================================================

============================================================================
*/