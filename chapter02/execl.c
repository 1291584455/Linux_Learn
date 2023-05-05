/*
#include <unistd.h>

       extern char **environ;

       int execl(const char *path, const char *arg, ...)
            -参数：
                -path: 需要指定的执行文件的路径或者名称
                -arg: 可执行文件的参数列表 参数必须以NULL 结尾

            - 返回值：
                    The exec() functions return only if an error has occurred.  The return value is -1, and errno is set to indicate the error.

*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{

    pid_t pid = fork();

    if (pid > 0)
    {
        printf("childpid: %d parent: pid %d\n", pid, getpid());
        sleep(1);
    }
    else if (pid == 0)
    {
        printf("child: %d\n", getpid());
        execl("./a.out", "", NULL);
        printf("child");
    }
    for (int i = 0; i < 5; i++)
    {
        printf("pid: %d i: %d\n", getpid(), i);
    }
    return 0;
}