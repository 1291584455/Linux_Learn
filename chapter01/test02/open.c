/*
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    // 打开已经存在的文件
    int open(const char *pathname, int flags);
        -flags:    文件操作的权限设置和一些其他的设置
                O_RDONLY, O_WRONLY, or O_RDWR
        -返回值：  返回文件描述符
            open(), openat(), and creat() return the new file descriptor, or -1 if an error occurred (in which case, errno is set appropriately).

            errno 属于Linux系统函数库，库里面的一个全局变量，记录的是最近的错误号.
            The perror() function produces a message on standard error describing the last error encountered during a call to a system or library function.
            void perror(const char *s);

    //创建一个新的文件
    int open(const char *pathname, int flags, mode_t mode);
        - mode: 八进制数 表示新文件的权限

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd = open("a.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
    }
    close(fd);
    return 0;
}