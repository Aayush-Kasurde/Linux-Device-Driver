#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* This function will handle all 
 * signal send to this program 
 */
void signal_handler(int sig)
{
	printf("Signal Handler is called %d\n", sig);
	/* Here we are supressing default behavior of SIGINT 
	 * by returning with new action
	 */
}

int main()
{
	/* Select function which will handle Ctrl + c / SIGINT */
	(void) signal(SIGINT, signal_handler);
	while(1) {
		printf("Hello World\n");
		sleep(10);
	}
}
