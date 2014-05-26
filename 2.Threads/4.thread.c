#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Declare prototype of thread function */
void *thread_function(void *arg);

char message[] = "Hello Thread";

int main()
{
	int res;
	/* Thread details */
	pthread_t a_thread;
	void *thread_result;
	
	printf("Message is now %s\n", message);
	/* Create thread using address of a_thread 
	 * We dont want to change attributes of thread so second argument is NULL
	 * Name of function
	 * Parameter to pass to thread
	 */
	res = pthread_create(&a_thread, NULL, thread_function, (void *) message);
	if (res != 0) {
		perror("Unable to create thread");
		exit(1);
	}

	printf("Waiting for thread to join\n");
	/* We are waiting for thread to finish its task and 
	 * storing it in thread_result
	 */
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Unable to join thread");
		exit(1);
	}
	printf("Thread joined with return %s\n", (char *)thread_result);
	printf("Message is now %s\n", message);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	printf("Thread function is running %s\n", (char *)arg);
	printf("Sleeping for 3 seconds\n");
	sleep(3);
	strcpy(message, "Bye");
	pthread_exit("Thank you for using CPU");
}
