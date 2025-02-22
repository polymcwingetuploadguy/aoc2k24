#include <stdio.h>
#include <stdlib.h>

int sortshit(const void *onevoid, const void *twovoid)
{
	const int *one = onevoid, *two = twovoid;
	if (*one > *two)
		return 1;
	if (*one < *two)
		return -1;
	return 0;
}

int main(void)
{
	FILE *input = fopen("input.txt", "r");
	char buffer[100];
	int *one = NULL, *two = NULL, i, sum = 0;
	for (i = 0; fgets(buffer, 100, input) != NULL; i++) {
		if ((one = realloc(one, (i + 1) * sizeof(int))) == NULL)
			return 1;
		if ((two = realloc(two, (i + 1) * sizeof(int))) == NULL)
			return 1;
		sscanf(buffer, "%d%d", &one[i], &two[i]);
	}
	fclose(input);
	qsort(one, i, sizeof(int), sortshit);
	qsort(two, i, sizeof(int), sortshit);
	for (int j = 0; j < i; j++)
		printf("%d\n", sum += one[j] > two[j] ? one[j] - two[j] : two[j] - one[j]);
	free(one);
	free(two);
}
