/*
============================================================================
Name : que19(a & b)
Author : Rishu Agrawal
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 21 September, 2025.
============================================================================
*/

/*
============================================================================
OUTPUT (A):-
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ mknod myfifo_cmd p
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ls -l myfifo_cmd
prw-rw-r-- 1 lenovo lenovo 0 Sep 21 14:24 myfifo_cmd

OUTPUT(B):-
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ mkfifo myfifo_mkf
lenovo@lenovo-IdeaPad-3-15IML05-U:~/HANDSONLIST_2$ ls -l myfifo_mkf
prw-rw-r-- 1 lenovo lenovo 0 Sep 21 14:25 myfifo_mkf

OUTPUT (C):-

============================================================================
*/