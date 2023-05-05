#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

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
        int flag = fcntl(pfd[0], F_GETFL);
        flag |= O_NONBLOCK;
        int ret = fcntl(pfd[0], F_SETFL, flag);

        while ((len = read(pfd[0], buf, sizeof(buf) - 1)) != 0)
        {
            printf("len %d recv %s\n", len, buf);
            memset(buf, 0, sizeof buf);
            sleep(3);
        }
        printf("exit\n");
        close(pfd[0]);
    }
    else if (pid > 0)
    {
        close(pfd[0]);
        printf("parent pid: %d\n", getpid());
        char *s = "nihaonihao";
        while (1)
        {
            write(pfd[1], s, strlen(s));
            sleep(5);
        }
    }
    return 0;
}