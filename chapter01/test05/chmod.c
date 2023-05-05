/*
        #include <sys/stat.h>
        int chmod(const char *pathname, mode_t mode);
            修改文件权限
        int fchmod(int fd, mode_t mode);
*/

#include <stdio.h>
#include <sys/stat.h>

int main()
{
    int ret = chmod("a.txt", 0777);
    if (ret == -1)
    {
        perror("chmod");
        return -1;
    }
    return 0;
}