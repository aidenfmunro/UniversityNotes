#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
    int fds[2];
    pipe (fds);
    pid_t pid = fork();

    if (pid > 0)
    {
        printf ("parent: %d\n", getpid());

        write (fds[1], "hello", 6);

        int status = 0;

        waitpid (pid, &status, WNOHANG);

        printf ("Ret code: %d\n", WEXITSTATUS(status));
    }
    else if (pid == 0)
    {
        printf ("child: %d\n\n", getpid());

        char buf[4096] = {};

        int ret = read (fds[0], buf, sizeof (buf));

        printf ("%s\n", buf);

        fflush (stdout); // doesn't work without fflush, why?

        // execl ("/bin/ls", "ll", NULL);
    }

    return 0;
}
