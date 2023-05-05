/*
    模拟实现 ps aux | grep xxx
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{

    int pfd[2];
    int ret = pipe(pfd);

    if (ret == -1)
    {
        perror("pipe");
        return 0;
    }

    pid_t pid = fork();

    if (pid > 0)
    {
        close(pfd[1]);
        int len;
        char buf[1024 * 4] = {0};
        while ((len = read(pfd[0], buf, sizeof(buf) - 1)) != 0)
        {
            printf("%s \n", buf);
            memset(buf, 0, sizeof buf);
        }
    }
    else if (pid == 0)
    {
        // 文件描述符重定向
        close(pfd[0]);
        dup2(pfd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
    }
    else
    {
        perror("fork");
    }
}