#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("%s filename \n", argv[0]);
        return -1;
    }
    struct stat statbuf;
    int ret = stat(argv[1], &statbuf);
    if (ret == -1)
    {
        perror("stat");
        return -1;
    }

    // 获取文件类型和文件权限
    char perms[11] = {0};

    switch (statbuf.st_mode & __S_IFMT)
    {
    case __S_IFLNK:
        perms[0] = 'l';
        break;
    case __S_IFDIR:
        perms[0] = 'd';
        break;
    case __S_IFREG:
        perms[0] = '-';
        break;
    case __S_IFCHR:
        perms[0] = 'c';
        break;
    case __S_IFSOCK:
        perms[0] = 's';
    case __S_IFIFO:
        perms[0] = 'p';
    default:
        perms[0] = '?';
        break;
    }
    int mod = statbuf.st_mode & 0777;
    for (int i = 1; i <= 9; i++)
    {
        switch (i % 3)
        {
        case 0:
            perms[i] = (mod >> (9 - i) & 1) ? 'r' : '-';
            break;
        case 1:
            perms[i] = (mod >> (9 - i) & 1) ? 'w' : '-';
            break;
        case 2:
            perms[i] = (mod >> (9 - i) & 1) ? 'x' : '-';
            break;
        default:
            break;
        }
    }

    // 硬链接数

    int linkNum = statbuf.st_nlink;

    // 文件所有者
    char *fileUser = getpwuid(statbuf.st_uid)->pw_name;

    // 文件所在组
    char *fileGrp = getgrgid(statbuf.st_gid)->gr_name;

    // 文件大小
    long int fileSize = statbuf.st_size;

    // 修改时间
    char *time = ctime(&statbuf.st_mtime);

    char mtime[512] = {0};
    strncpy(mtime, time, strlen(time) - 1);

    char buf[1024];
    sprintf(buf, "%s %d %s %s %ld %s %s", perms, linkNum, fileUser, fileGrp, fileSize, mtime, argv[1]);
    printf("%s\n", buf);
    return 0;
}