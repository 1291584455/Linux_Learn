#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    // 打开管道文件
    int fd = open("fifo1", O_RDONLY);
    printf("read\n");
    char buf[1024] = {0};
    int len;
    while ((len = read(fd, buf, sizeof(buf) - 1)) != 0)
    {
        printf("%s", buf);
    }

    return 0;
}