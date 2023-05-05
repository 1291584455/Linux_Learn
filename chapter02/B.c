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

    pid_t pid = fork();

    // 父进程用于向管道bfifo写数据
    // 子进程用于向管道afifo读数据
    if (pid > 0)
    {
        int bfd = open("bfifo", O_WRONLY);
        printf("B pid: %d\n", getpid());
        char s[1024];
        while (1)
        {
            memset(s, 0, sizeof s);
            printf("B send:");
            fgets(s, N, stdin);
            printf("\n");
            if (strcmp(s, "exit") == 0)
            {
                char *message = "B exit";
                write(bfd, message, strlen(message));
                close(bfd);
                break;
            }
            write(bfd, s, sizeof s);
        }
    }
    else if (pid == 0)
    {
        int afd = open("afifo", O_RDONLY);
        char s[1024];
        int len;
        while (1)
        {
            memset(s, 0, sizeof s);
            len = read(afd, s, sizeof s);
            if (len == -1)
            {
                close(afd);
                break;
            }
            if (strcmp(s, "A exit") == 0)
            {
                close(afd);
                break;
            }
            printf("B recv: %s", s);
        }
    }
    else
    {
        perror("fork");
    }

    return 0;
}