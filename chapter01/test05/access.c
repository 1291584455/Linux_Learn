/*
    #include <unistd.h>

    int access(const char *pathname, int mode);
        判断文件是否有某个权限，或者判断文件是否存在
        access() checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced.
        The  mode specifies the accessibility check(s) to be performed, and is either the value F_OK, or a mask consisting of the bitwise OR of one or more of R_OK, W_OK, and X_OK.  F_OK tests
        for the existence of the file.  R_OK, W_OK, and X_OK test whether the file exists and grants read, write, and execute permissions, respectively.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{

    int ret = access("a.txt", F_OK);
    if (ret == -1)
    {
        printf("file not exits\n");
        return -1;
    }

    return 0;
}