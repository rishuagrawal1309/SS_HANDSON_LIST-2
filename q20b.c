/*
============================================================================
Name : que20
Author : Rishu Agrawal
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21 September, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "myfifo";
    char message[100];

    int fd = open(fifo_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    read(fd, message, sizeof(message));
    printf("Received message: %s", message);

    close(fd);
    return 0;
}

/*
============================================================================
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q20b.c -o q20b
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./q20b
Received message: hyy
============================================================================
*/