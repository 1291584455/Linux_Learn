#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("pid : %d hello world\n", getpid());
	return 0;
}
