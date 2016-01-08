#include "Header.h"

int main(void)
{
	Queue myQueue = {NULL, NULL};

	char *word = "hello";

	enqueue(&myQueue, word);

	if(!is_empty(&myQueue))
	{
		dequeue(&myQueue, word);
	}

	if(!is_empty(&myQueue))
	{
		printf("%s", word);
	}

	return 0;
}