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
    const char *fifo_write = "fifo2";
    const char *fifo_read  = "fifo1";  
    char buffer[100];

    int fd_r = open(fifo_read, O_RDONLY);
    if (fd_r == -1) { perror("open read fifo"); exit(1); }

    int fd_w = open(fifo_write, O_WRONLY);
    if (fd_w == -1) { perror("open write fifo"); exit(1); }

    while (1) {
       
        read(fd_r, buffer, sizeof(buffer));
        printf("A: %s\n", buffer);

        printf("B: Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(fd_w, buffer, strlen(buffer)+1);
    }

    close(fd_r);
    close(fd_w);
    return 0;
}

/*
============================================================================
U:~/HANDSONLIST_2$ gcc q21b.c -o q21b
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./q21b
A: Hello.. how you doing?

B: Enter message: heyy.. i m doing great. what about you?
A: i am also doing fine. 

B: Enter message: okk.. bye.. see u
A: byee..
============================================================================
*/