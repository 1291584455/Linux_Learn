/*
    SYNOPSIS
       #include <sys/types.h>
       #include <sys/wait.h>

       pid_t wait(int *wstatus);

       pid_t waitpid(pid_t pid, int *wstatus, int options);

       return:
            wait(): on success, returns the process ID of the terminated child; on error, -1 is returned.

            waitpid(): on success, returns the process ID of the child whose state has changed; if WNOHANG was specified and one or more child(ren) specified by pid  exist,
            but have not yet changed state, then 0 is returned.  On error, -1 is returned.

            waitid(): returns 0 on success or if WNOHANG was specified and no child(ren) specified by id has yet changed state; on error, -1 is returned.

            Each of these calls sets errno to an appropriate value in the case of an error.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    for (int i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
    }
    if (pid > 0)
    {
        while (1)
        {
            printf("parent hello \n");
            sleep(1);
        }

        while (1)
        {
            printf("parent, pid: %d\n", getpid());
            int ret = wait(NULL);
            if (ret == -1)
            {
                break;
            }
        }
    }
    else if (pid == 0)
    {
        printf("child, pid: %d\n", getpid());
        sleep(1);
    }
    return 0;
}