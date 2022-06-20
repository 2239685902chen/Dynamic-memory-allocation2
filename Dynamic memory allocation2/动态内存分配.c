#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
	int* q = calloc(5, sizeof(int));
	if (q == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	else
	{
		int w = 0;
		for (w = 0; w < 5; w++)
		{
			*(q + w) = w;
			printf("%d ", *(q + w));
		}
		printf("\n");
	}
	int* q1 = realloc(q, 10 * sizeof(int));//realloc第二个参数是你修改后内存的大小
	if (q1 == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int w = 0;
		for (w = 5; w < 10; w++)
		{
			*(q1 + w) = w;
			printf("%d ", *(q1 + w));
		}
		printf("\n");
	}
	int w = 0;
	for (w = 0; w < 10; w++)
	{
		printf("%d ", *(q1 + w));
	}
	printf("\n");
	free(q1);
	q1 = NULL;
	return 0;
}