#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * @array: array of int
 * @size: the size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, m, d;
	int temp;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (m = size - 1; d = i + 1; m > i; m--)
		{
			if (array[m] < array[d])
			{
				d = m;
			}
		}
		if (array[i] > array[d])
		{
			temp = array[i];
			array[i] = array[d];
			array[d] = temp;
			print_array(array, size);
		}
	}
}
