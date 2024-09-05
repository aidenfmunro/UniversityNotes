#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

const int n_pids = 10;

int main ()
{
    pid_t pids[n_pids] = {};

    for (int i = n_pids - 1; i >= 0; i--)
    {
        pids[i] = fork ();
        if (pids[i] == 0)
        {
            sleep (i + 1);
            printf ("terminate: %d\n", getpid());
            exit (0);
        }
    }

    for (int i = n_pids - 1; i >= 0; i--)
    {
        waitpid (pids[i], NULL, 0);
    }

    return 0;
}
