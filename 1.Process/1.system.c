#include <stdio.h>

int main()
{
	printf("Starting ps using system() call\n");
	system("ps -ef");
	return 0;
}
