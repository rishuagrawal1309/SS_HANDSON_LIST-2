/*
============================================================================
Name : que33
Author : Rishu Agrawal
Description : Write a program to communicate between two machines using socket.
Date: 01 October, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[1024];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY; 
    addr.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 1);

    printf("Server waiting for connection...\n");
    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, buffer, 1024);
    printf("Client says: %s\n", buffer);

    char *msg = "Hello from server";
    write(client_fd, msg, strlen(msg));

    close(client_fd);
    close(server_fd);
    return 0;
}

/*
============================================================================
TERMINAL 1 - 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q33_server.c -o q33_server
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q33_client.c -o q33_client
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./q33_server
Server waiting for connection...
Client says: Hello from client

TERMINAL 2 - 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./q33_client
Server says: Hello from server
============================================================================
*/