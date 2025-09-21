/*
============================================================================
Name : que22
Author : Rishu Agrawal
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21 September, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "fifo_select";

    if (mkfifo(fifo_name, 0666) == -1) {
 
        perror("mkfifo (may already exist)");
    }

    int fd = open(fifo_name, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open fifo");
        exit(1);
    }

    fd_set readfds;
    struct timeval timeout;
    int ret;

    printf("Waiting for data on FIFO '%s' for 10 seconds...\n", fifo_name);

    FD_ZERO(&readfds);    
    FD_SET(fd, &readfds);  

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("Timeout: No data written in 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            char buffer[100];
            int n = read(fd, buffer, sizeof(buffer)-1);
            if (n > 0) {
                buffer[n] = '\0';
                printf("Data received: %s\n", buffer);
            }
        }
    }

    close(fd);
    return 0;
}

/*
============================================================================
TERMINAL 1 :-
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q22.c -o q22
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./q22
mkfifo (may already exist): File exists
Waiting for data on FIFO 'fifo_select' for 10 seconds...
Data received: hello fifo

TERMINAL 2:-
echo "hello fifo" > fifo_select
============================================================================
*/