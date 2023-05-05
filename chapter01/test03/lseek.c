/*
    标准 C 库函数
    #include <stdio.h>
    int fseek(FILE *stream, long offset, int whence);


    Linux系统函数

    #include <sys/types.h>
    #include <unistd.h>

    off_t lseek(int fd, off_t offset, int whence);

*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("hello.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    int ret = lseek(fd, 100, SEEK_END);
    if (ret == -1)
    {
        perror("lseek");
    }
    write(fd, " ", 1);

    close(fd);
    return 0;
}