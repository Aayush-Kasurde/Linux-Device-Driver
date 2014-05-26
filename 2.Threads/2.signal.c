#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* This function will handle all 
 * signal send to this program 
 */
void signal_handler(int sig)
{
	printf("Signal Handler is called %d\n", sig);
	/* Here we are handling the SIGINT to default behaivor
	 * When you press first ctrl + c it will not be interputted 
         * For subsequent, SIGINT is handled
       	 */
	(void) signal(SIGINT, SIG_DFL);
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
