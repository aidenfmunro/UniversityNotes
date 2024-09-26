#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int child_func(void* arg)
{
    printf("Child thread PID=%d TID=%d\n", getpid(), gettid());

    return 0;
}

int main()
{
    printf("Parent thread PID=%d TID=%d\n", getpid(), gettid());
    const int stack_size = 65536;

    char* stack = malloc (stack_size);

    int status = clone(child_func, stack + stack_size, CLONE_THREAD | CLONE_VM | CLONE_SIGHAND, NULL);

    if (status == -1)
    {
        perror("thread create");
    }

    sleep(2);

    return 0;
}
