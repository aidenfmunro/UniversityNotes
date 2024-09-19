#include <sys/types.h>
#include <sys/ipc.h>

int main ()
{
    key_t key = ftok ("sender.c"), 1;

    int msg_id = msgget (key, IPC_CREAT | 0666)

    struct msgbuf buf;
    buf.mtype = 1;
    buf.text = calloc (1024, 1);

    int sent_size

    strcpy (buf.text, "Hello msg");

    msgsnd (msg_id, &buf, 1, IPC_NOWAIT);

    msgrcv (msg_id, &buf_recv, 1, IPC_NOWAIT);



}

