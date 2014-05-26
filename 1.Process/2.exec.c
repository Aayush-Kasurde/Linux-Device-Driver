#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SHELL "/bin/sh"

int main()
{
	int status;	/* Store status */
	pid_t pid;	/* Store details about PID*/

	pid = fork();
	if (pid == 0)
	{
		/* This is the child process.  Execute the shell command. */
		execl(SHELL, SHELL, "-c", "ls", NULL);
		_exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		/* The fork failed.  Report failure.  */
		status = -1;
	else
		/* This is the parent process.  Wait for the child to complete. */
		if (waitpid(pid, &status, 0) != pid)
			status = -1;
	return status;
}
