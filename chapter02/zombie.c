#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();
    // 判断是父进程还是子进程
    if (pid > 0)
    {
        // 当前是父进程
        while (1)
        {
            printf("parent pid: %d ppid: %d \n", getpid(), getppid());
            sleep(1);
        }
    }
    else if (pid == 0)
    {
        printf("child pid: %d ppid: %d\n", getpid(), getppid());
    }
    else
    {
        perror("fork");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("pid: %d i: %d\n", getpid(), i);
        sleep(1);
    }
    return 0;
}