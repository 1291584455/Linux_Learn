/*

    SIGALRM 默认终止当前进程

    SYNOPSIS
        #include <unistd.h>

        unsigned int alarm(unsigned int seconds);

    DESCRIPTION
        alarm() arranges for a SIGALRM signal to be delivered to the calling process in seconds seconds.

        If seconds is zero, any pending alarm is canceled.

        In any event any previously set alarm() is canceled.

        RETURN VALUE
       alarm() returns the number of seconds remaining until any previously scheduled alarm was due to be delivered, or zero if there was no previously scheduled alarm.
*/

#include "mhead.h"

int main()
{
    alarm(5);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}