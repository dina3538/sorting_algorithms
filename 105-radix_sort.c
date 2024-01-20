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
	const int radix = 10;
	int *output = malloc(sizeof(int) * size);

	if (output == NULL)
		return;

	count = malloc(sizeof(int) * radix);

	if (count == NULL)
	{
		free(output);
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
		output[count[(array[j] / exp) % radix] - 1] = array[j];
		count[(array[j] / exp) % radix]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];


	free(output);
	free(count);	
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix Sort (LSD)
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum number to determine the number of digits */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Perform counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_(array, size, exp);
		print_array(array, size);
	}
}
