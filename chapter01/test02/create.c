#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{

    int fd = open("create.txt", O_RDWR | O_CREAT, 0777);
    close(fd);
    return 0;
}