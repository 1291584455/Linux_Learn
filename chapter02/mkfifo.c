/*
    #include <sys/types.h>
    #include <sys/stat.h>

    int mkfifo(const char *pathname, mode_t mode);
        参数：
            -pathname: 管道名称
            -mode: 权限

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    int ret = mkfifo("fifo1", 0664);
    if (ret == -1)
    {
        perror("mkfifo");
    }
    return 0;
}