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
    int sock;
    struct sockaddr_in addr;
    char buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "SERVER_IP", &addr.sin_addr);  

    connect(sock, (struct sockaddr *)&addr, sizeof(addr));

    char *msg = "Hello from client";
    write(sock, msg, strlen(msg));

    read(sock, buffer, 1024);
    printf("Server says: %s\n", buffer);

    close(sock);
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