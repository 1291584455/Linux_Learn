#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

const int N = 1024;

int main()
{
    printf("hhhhh\n");
    int ok = access("afifo", F_OK);
    if (ok == -1)
    {
        int ret = mkfifo("afifo", 0664);
        if (ret == -1)
        {
            perror("mkfifo");
            return 0;
        }
    }
    ok = access("bfifo", F_OK);
    if (ok == -1)
    {
        int ret = mkfifo("bfifo", 0664);
        if (ret == -1)
        {
            perror("mkfifo");
            return 0;
        }
    }

    pid_t pid = fork();
    // 父进程用于向管道afifo写数据
    // 子进程用于向管道bfifo读数据
    if (pid > 0)
    {
        int afd = open("afifo", O_WRONLY);
        printf("A pid: %d\n", getpid());
        char s[1024];
        while (1)
        {
            memset(s, 0, sizeof s);
            printf("A send:");
            fgets(s, N, stdin);
            printf("\n");
            if (strcmp(s, "exit") == 0)
            {
                char *message = "A exit";
                write(afd, message, strlen(message));
                close(afd);
                break;
            }
            write(afd, s, sizeof s);
        }
    }
    else if (pid == 0)
    {
        printf("A child pid: %d", getpid());
        int bfd = open("bfifo", O_RDONLY);
        char s[1024];
        int len;
        while (1)
        {
            memset(s, 0, sizeof s);
            len = read(bfd, s, sizeof s);
            if (len == -1 || len == 0)
            {
                close(bfd);
                break;
            }
            if (strcmp(s, "B exit") == 0)
            {
                close(bfd);
                break;
            }
            printf("A recv: %s", s);
        }
    }
    else
    {
        perror("fork");
    }

    return 0;
}