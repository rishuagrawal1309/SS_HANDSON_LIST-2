/*
============================================================================
Name : que21
Author : Rishu Agrawal
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 21 September, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo_write = "fifo1";  
    const char *fifo_read  = "fifo2"; 
    char buffer[100];

    int fd_w = open(fifo_write, O_WRONLY);
    if (fd_w == -1) { perror("open write fifo"); exit(1); }

    int fd_r = open(fifo_read, O_RDONLY);
    if (fd_r == -1) { perror("open read fifo"); exit(1); }

    while (1) {
        printf("A: Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);

        write(fd_w, buffer, strlen(buffer)+1);

       
        read(fd_r, buffer, sizeof(buffer));
        printf("B: %s\n", buffer);
    }

    close(fd_w);
    close(fd_r);
    return 0;
}

/*
============================================================================
U:~/HANDSONLIST_2$ gcc q21a.c -o q21a
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./q21a
A: Enter message: Hello.. how you doing?
B: heyy.. i m doing great. what about you?

A: Enter message: i am also doing fine. 
B: okk.. bye.. see u

A: Enter message: byee..
============================================================================
*/