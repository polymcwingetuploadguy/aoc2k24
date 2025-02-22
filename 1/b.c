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
	if (input == NULL)
		return 1;
	char buffer[100];
	int *one = NULL, *two = NULL, i, similarity = 0;
	for (i = 0; fgets(buffer, 100, input) != NULL; i++) {
		if ((one = realloc(one, (i + 1) * sizeof(int))) == NULL)
			return 1;
		if ((two = realloc(two, (i + 1) * sizeof(int))) == NULL)
			return 1;
		sscanf(buffer, "%d%d", &one[i], &two[i]);
	}
	fclose(input);
	for (int j = 0; j < i; j++) {
		for (int k = 0; k < i; k++) {
			if (one[j] == two[k])
				similarity += two[k];
		}
	}
	printf("%d\n", similarity);
	free(one);
	free(two);
}
