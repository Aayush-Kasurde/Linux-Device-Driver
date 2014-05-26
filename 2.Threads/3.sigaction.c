#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* This function will handle all 
 * signal send to this program 
 */
void signal_handler(int sig)
{
	printf("Signal Handler is called %d\n", sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, 0);

	while(1) {
		printf("Hello World\n");
		sleep(10);
	}
}
