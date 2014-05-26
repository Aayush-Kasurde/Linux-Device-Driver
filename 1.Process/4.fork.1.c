#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	char *message; 
	int n, exit_code;

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
			exit_code = 37;
			break;
		default:
			message = "This is the parent speaking\n";
			n = 3;
			exit_code = 0;
			break;
	}
	for (; n > 0; n--) {
		printf("#%d %s\n", n, message);
		sleep(1);
	}
	
	if (pid != 0) {
		int stat_val;
		pid_t child_pid;
		child_pid = wait(&stat_val);
		printf("Child has finished PID = %d\n", child_pid);
		if (WIFEXITED(stat_val))
			printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
		else
			printf("Child exited with abnormally\n");
	}
	exit(exit_code);
}
