/**
    #include <unistd.h>
    ssize_t read(int fd, void *buf, size_t count);
        - buf: 读取数据存放的地方，数组的地址，
        -count: 指定数组的大小


    ssize_t write(int fd, const void *buf, size_t count);
        return:
            On success, the number of bytes written is returned (zero indicates nothing was written).  It is not an error if this number is smaller than the number of  bytes  requested;  this  may
            happen for example because the disk device was filled.  See also NOTES.

            On error, -1 is returned, and errno is set appropriately.

            If count is zero and fd refers to a regular file, then write() may return a failure status if one of the errors below is detected.  If no errors are detected, or error detection is not
            performed, 0 will be returned without causing any other effect.  If count is zero and fd refers to a file other than a regular file, the results are not specified.


*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // 打开源文件
    int fd = open("../main.cpp", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    // 打开目标文件
    int cfd = open("copy.c", O_WRONLY | O_CREAT, 0664);

    // 定义buf数组
    char buf[1024] = {0};

    int len;
    while ((len = read(fd, buf, sizeof buf)) > 0)
    {
        write(cfd, buf, len);
    }

    // 关闭文件
    close(fd);
    close(cfd);
    return 0;
}