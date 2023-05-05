#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char s[20] = {'a', 'b'};
    while (1)
    {
        scanf("%s", s + 1);
        for (int i = 0; i < 20; i++)
        {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}