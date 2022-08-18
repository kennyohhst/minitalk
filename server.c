#include "minitalk.h"

int main(void)
{
    pid_t mypid;

    mypid = getpid();
    printf("This is my PID: %d\n", mypid);
    while (1)
        pause();
}