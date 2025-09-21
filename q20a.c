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

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
   
    }

    int fd = open(fifo_name, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    write(fd, message, sizeof(message));
    printf("Message sent!\n");

    close(fd);
    return 0;
}

/*
============================================================================
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q20a.c -o q20a
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./q20a
mkfifo: File exists
Enter a message to send: hyy
Message sent!
============================================================================
*/