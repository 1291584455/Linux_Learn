/*
    #include <sys/types.h>
       #include <signal.h>

       int kill(pid_t pid, int sig);

    Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       kill(): _POSIX_C_SOURCE

    DESCRIPTION
        The kill() system call can be used to send any signal to any process group or process.

        If pid is positive, then signal sig is sent to the process with the ID specified by pid.

       If pid equals 0, then sig is sent to every process in the process group of the calling process.

       If pid equals -1, then sig is sent to every process for which the calling process has permission to send signals, except for process 1 (init), but see below.

       If pid is less than -1, then sig is sent to every process in the process group whose ID is -pid.


       NAME
       raise - send a signal to the caller

        SYNOPSIS
            #include <signal.h>

            int raise(int sig);

        DESCRIPTION
            The raise() function sends a signal to the calling process or thread.  In a single-threaded program it is equivalent to

                kill(getpid(), sig);

        ABORT(3)                                                                    Linux Programmer's Manual                                                                   ABORT(3)

NAME
       abort - cause abnormal process termination

SYNOPSIS
       #include <stdlib.h>

       void abort(void);

DESCRIPTION
       The  abort() first unblocks the SIGABRT signal, and then raises that signal for the calling process (as though raise(3) was called).  This results in the abnormal termi‐
       nation of the process unless the SIGABRT signal is caught and the signal handler does not return (see longjmp(3)).
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    pid_t pid = fork();

    if (pid > 0)
    {
        printf("parent start\n");
        sleep(2);
        printf("send kill singal\n");
        kill(pid, SIGINT);
    }
    else if (pid == 0)
    {
        printf("child start\n");
        for (int i = 0; i < 10; i++)
        {
            printf("child worlk\n");
            sleep(1);
        }
    }
}