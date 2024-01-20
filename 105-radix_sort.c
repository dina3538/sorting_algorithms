#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * counting_ - Performs counting sort for a specific digit (exp)
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current digit to consider
 */

void counting_(int *array, size_t size, int exp)
{
	int *count, i;
	size_t j;
	int *out;
	const int radix = 10;

	out = malloc(sizeof(int) * size);

	if (out == NULL)
		return;

	count = malloc(sizeof(int) * radix);

	if (count == NULL)
	{
		free(out);
		return;
	}

	for (i = 0; i < radix; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[(array[j] / exp) % radix]++;

	for (i = 1; i < radix; i++)
		count[i] += count[i - 1];

	for (j = size - 1; j < size; j--)
	{
		out[count[(array[j] / exp) % radix] - 1] = array[j];
		count[(array[j] / exp) % radix]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(out);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers
 * @array: The array to be sorted
 * @size: Number of elements
 */
void radix_sort(int *array, size_t size)
{
	int beg, exp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	beg = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > beg)
			beg = array[i];
	}

	for (exp = 1; beg / exp > 0; exp *= 10)
	{
		counting_(array, size, exp);
		print_array(array, size);
	}
}
