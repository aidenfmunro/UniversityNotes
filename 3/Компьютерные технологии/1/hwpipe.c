#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void run_cmd (char* cmd)
{
    const pid_t pid = fork();
    if (pid < 0)
    {
        exit(1);
    }

    if (pid)
    {
        waitpid (pid, NULL, 0);

        return;
    }
    else
    {
        char** args = parse_cmd(cmd);
        execvp (args[0], args);
    }

    return;
}

int main ()
{
    while (1)
    {
        char* cmd = NULL;

        run_cmd(cmd);
    }
}
