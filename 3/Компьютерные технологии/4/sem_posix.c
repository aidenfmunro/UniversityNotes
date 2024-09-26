#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

const char* SEM_NAME = "/sem_name";

int main (int argc, char* argv[])
{
    sem_t* sem = NULL;
    sem = sem_open(SEM_NAME, O_CREAT, 0776, 0);

    if (sem == SEM_FAILED)
    {
        perror("sem open");
        exit(1);
    }

    if (argc == 2 && !strcmp(argv[1], "post"))
    {
        sem_post(sem);
        printf("Posted\n");
    }
    else
    {
        sem_wait(sem);
        printf("Somebody posted to the semaphore\n");
    }

    sem_unlink(SEM_NAME);

    return 0;
}
