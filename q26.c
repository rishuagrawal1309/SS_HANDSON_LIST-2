/*
============================================================================
Name : que26
Author : Rishu Agrawal
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 21 September, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 100
struct my_msg {
    long msg_type;     
    char msg_text[MAX_TEXT]; 
};

int main() {
    key_t key;
    int msgid;
    struct my_msg message;

    key = ftok("msgqueuefile", 65); 
    if (key == -1) {
        perror("ftok");
        exit(1);
    }
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    message.msg_type = 1; 
    printf("Enter a message to send: ");
    fgets(message.msg_text, MAX_TEXT, stdin);
    message.msg_text[strcspn(message.msg_text, "\n")] = '\0'; 

    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent successfully!\n");

    return 0;
}

/*
============================================================================
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q26.c
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Enter a message to send: hellooo how are you?
Message sent successfully!

lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x410644fb 0          lenovo     666        100          1   
============================================================================
*/