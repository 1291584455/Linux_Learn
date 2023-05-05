#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int ok = access("fifo1", F_OK);
    if (ok == -1)
    {
        int ret = mkfifo("fifo1", 0664);
        if (ret == -1)
        {
            perror("mkfifo");
            return 0;
        }
    }
    sleep(1);
    // 以只写的方式打开管道
    int fd = open("fifo1", O_WRONLY);
    char *s = "nihao";
    printf("write\n");
    write(fd, s, strlen(s));
    close(fd);

    return 0;
}