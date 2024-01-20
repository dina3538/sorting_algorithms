#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
void counting_sort(int *array, size_t size)
{
	size_t i;
	ssize_t k;
	int max;
	int *count_array, *sorted_array;
	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = calloc(max + 1, sizeof(int));
	if (count_array == NULL)
		return;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	print_array(array, size);
	for (k = 0; k <= max; k++)
	{
		if (count_array[k] > 0)
			printf(" %d,", count_array[k]);
	}
	printf("\n");
	for (k = 1; k <= max; k++)
		count_array[k] += count_array[k - 1];
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}
	for (k = size - 1; k >= 0; k--)
	{
		sorted_array[count_array[array[k]] - 1] = array[k];
		count_array[array[k]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	print_array(array, size);
	free(count_array);
	free(sorted_array);
}
