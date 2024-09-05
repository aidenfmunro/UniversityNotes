#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
    pid_t pid = fork();

    if (pid > 0)
    {
        printf ("parent: %d\n", getpid());

        int status = 0;

        waitpid (pid, &status, WNOHANG);

        printf ("Ret code: %d\n", WEXITSTATUS(status));
    }
    else if (pid == 0)
    {
        printf ("child: %d\n, child's parent: %d\n", getpid(), getppid());
        sleep (10);
        printf ("child: %d, child's parent: %d\n", getpid(), getppid());

        fflush (stdout); // doesn't work without fflush, why?

        // execl ("/bin/ls", "ll", NULL);
    }

    return 0;
}
