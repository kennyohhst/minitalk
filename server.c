#include "minitalk.h"
#include <signal.h>

void    ft_handle_sig(int signum)
{
	if (1 || signum)
		printf("\n\nhello\n\n");

    // if (signum == SIGUSR1)
    // {
    //     printf("you used sigusr1\n");
    //     // write(1, "0", 2);
    //     // write(1, "\n", 2);
    // }  
    // if (signum == SIGUSR2)
    // {    
    //     // printf("you used sugusr2\n");
    //     write(1, "2", 2);
    //     write(1, "\n", 2);
    // }
}

int main(void)
{
    pid_t               mypid;
    struct sigaction    my_act = { 0 };

    // signal(SIGUSR1, ft_handle_sig);
    // signal(SIGUSR2, ft_handle_sig);
    my_act.sa_handler = &ft_handle_sig;
    sigaction(SIGUSR2, &my_act, NULL);
    sigaction(SIGUSR1, &my_act, NULL);

    mypid = getpid();
    printf("This is my PID: %d\n", mypid);

    while (1)
        pause();
}