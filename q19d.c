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
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    const char *fifo_name = "myfifo";

    if (mknod(fifo_name, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        return 1;
    }

    printf("FIFO created successfully\n");
    return 0;
}

/*
============================================================================
FIFO created successfully
============================================================================
*/