#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct msgbuf
{
    long  mtype;
    char text[1024];
};

int main ()
{
    key_t key = ftok ("sender.c", 1);

    int msg_id = msgget (key, IPC_CREAT | 0666);

    struct msgbuf buf;
    buf.mtype = 1;

    char* msg = "Hello msg";

    int sent_size = sizeof(msg) + 1;

    strcpy (buf.text, msg);

    msgsnd (msg_id, &buf, sent_size, IPC_NOWAIT);

    struct msgbuf buf_rcv;

    msgrcv (msg_id, &buf_rcv, 1, buf.mtype, IPC_NOWAIT);

    printf ("%s\n", buf_rcv.text);
}
