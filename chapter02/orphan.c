#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();
    printf("%d\n", pid);
    // 判断是父进程还是子进程
    if (pid > 0)
    {
        // 当前是父进程
        printf("parent pid: %d ppid: %d \n", getpid(), getppid());
    }
    else if (pid == 0)
    {
        sleep(1);
        printf("child pid: %d ppid: %d\n", getpid(), getppid());
    }
    else
    {
        perror("fork");
    }

    for (int i = 0; i < 10; i++)
    {
        printf("pid: %d i: %d\n", getpid(), i);
    }
    return 0;
}