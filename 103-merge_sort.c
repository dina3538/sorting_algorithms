#include "sort.h"

/**
 * merge_find - compare
 * @array: te ints
 * @begin: first indx
 * @end: last indx
 * @add: ouput
 * Return: void
 */
void merge_find(int *array, size_t begin, size_t end, int *add)
{
	size_t i = begin, j, d, mid;

	j = mid = (begin + end) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, mid - begin);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (d = begin; d < end; d++)
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			add[d] = array[i++];
		}
		else
		{
			add[d] = array[j++];
		}
	printf("[Done]: ");
	print_array(add + begin, end - begin);
}

/**
 * top_down - sort top down
 * @array: the inta
 * @begin: first indx
 * @end: last indx
 * @add: output
 * Return: void
 */

void top_down(int *array, size_t begin, size_t end, int *add)
{
	size_t midd;

	midd = (begin + end) / 2;
	if (end - begin < 2)
	{
		return;
	}
	top_down(add, begin, midd, array);
	top_down(add, midd, end, array);
	merge_find(array, begin, end, add);
}

/**
 * merge_sort - sort by merge sort
 * @array: array ints
 * @size: the size
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *add;
	size_t x;

	if (!array || size < 2)
		return;

	add = malloc(sizeof(int) * size);
	if (!add)
		return;
	for (x = 0; x < size; x++)
		add[x] = array[x];
	top_down(add, 0, size, array);
	free(add);
}
