/*
    #include <unistd.h>

    int pipe(int pipefd[2]);
    创建匿名管道用于进程间的通信

    pipe()  creates  a  pipe, a unidirectional data channel that can be used for interprocess communication.  The array pipefd is used to return two file descriptors referring to
    the ends of the pipe.  pipefd[0] refers to the read end of the pipe.  pipefd[1] refers to the write end of the pipe.  Data written to the write end of the pipe is buffered by
    the kernel until it is read from the read end of the pipe.  For further details, see pipe(7).


    return :
        On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.

        On Linux (and other systems), pipe() does not modify pipefd on failure.  A requirement standardizing this behavior was added in POSIX.1-2016.  The Linux-specific pipe2() sys‐
        tem call likewise does not modify pipefd on failure.

    匿名管道只能用于有关系的进程之间的通信

*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int pfd[2];
    int ret = pipe(pfd);
    pid_t pid = fork();

    if (pid == 0)
    {
        close(pfd[1]);
        printf("child pid: %d\n", getpid());
        char buf[1024] = {0};
        int len;
        while ((len = read(pfd[0], buf, sizeof buf)) != 0)
        {
            printf("recv %s\n", buf);
            memset(buf, 0, sizeof buf);
        }
        printf("exit\n");
        close(pfd[0]);
    }
    else if (pid > 0)
    {
        close(pfd[0]);
        printf("parent pid: %d\n", getpid());
        char s[1024];
        while (1)
        {
            memset(s, 0, sizeof s);
            scanf("%s", s);
            if (strcmp(s, "exit") == 0)
            {
                close(pfd[1]);
                return 0;
            }
            printf("send %s\n", s);
            write(pfd[1], s, sizeof s);
        }
    }
    return 0;
}