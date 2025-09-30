/*
============================================================================
Name : que27 b
Author : Rishu Agrawal
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 30 September, 2025.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct msg
{
    long type;
    char text[100];
};

int main()
{
    key_t key = ftok("msgqueuefile",65);
    int msgid= msgget(key,0666);

    struct msg m;
    msgrcv(msgid, &m, sizeof(m.text), 1, IPC_NOWAIT);
    printf("Received (non blocking) : %s \n", m.text);
    return 0;
}
/*
============================================================================
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q26.c
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Enter a message to send: Shruti
Message sent successfully!
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Enter a message to send: Swayam
Message sent successfully!
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Enter a message to send: Abhijeet
Message sent successfully!
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Enter a message to send: Rishu
Message sent successfully!


lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ gcc q27b.c
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Received (non blocking) : Shruti 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Received (non blocking) : Swayam 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Received (non blocking) : Abhijeet 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Received (non blocking) : Rishu 
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ./a.out
Received (non blocking) :  
============================================================================
*/