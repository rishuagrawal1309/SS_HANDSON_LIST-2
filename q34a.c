/*
============================================================================
Name : que34
Author : Rishu Agrawal
Description : Write a program to create a concurrent server.
a. use fork
Date: 01 October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[1024];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); exit(1); }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY; 
    addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind"); exit(1);
    }

    if (listen(server_fd, 5) < 0) { perror("listen"); exit(1); }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) continue;

        if (fork() == 0) {  
            close(server_fd); 

            read(client_fd, buffer, sizeof(buffer));
            printf("Client says: %s\n", buffer);

            char *msg = "Hello from server (fork)";
            write(client_fd, msg, strlen(msg));

            close(client_fd);
            exit(0); 
        }
        close(client_fd); 
    }

    close(server_fd);
    return 0;
}


/*
============================================================================
TERMINAL 1 :-
Server listening on port 8080...
Client says : Hello from client

TERMINAL 2 :-
Server says : Hello from server (fork)
============================================================================
*/