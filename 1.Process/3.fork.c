#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	char *message; 
	int n;
	
	printf("Fork program start\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("Unable to fork");
			exit(1);
		case 0:
			message = "This is the child speaking\n";
			n = 5;
			break;
		default:
			message = "This is the parent speaking\n";
			n = 3;
			break;
	}
	for (; n > 0; n--) {
		printf("#%d %s\n", n, message);
		sleep(1);
	}
	exit(0);
}
