/*
============================================================================
Name : que34
Author : Rishu Agrawal
Description : Write a program to create a concurrent server.
b. use pthread_create
Date: 01 October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

void *handle_client(void *arg) {
    int client_fd = *(int *)arg;
    char buffer[1024];
    free(arg);

    read(client_fd, buffer, 1024);
    printf("Client says: %s\n", buffer);

    char *msg = "Hello from server (thread)";
    write(client_fd, msg, strlen(msg));
    close(client_fd);
    return NULL;
}

int main() {
    int server_fd;
    struct sockaddr_in addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 5);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int *client_fd = malloc(sizeof(int));
        *client_fd = accept(server_fd, NULL, NULL);
        if (*client_fd < 0) {
            free(client_fd);
            continue;
        }

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client_fd);
        pthread_detach(tid); 
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
Server says : Hello from server (thread)
============================================================================
*/