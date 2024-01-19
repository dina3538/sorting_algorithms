#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: Number of elems
 */
void shell_sort(int *array, size_t size)
{
	size_t k;
	size_t i;

	if (array == NULL || size < 2)
		return;

	k = 1;

	while (k < size / 3)
		k = k * 3 + 1;

	while (k > 0)
	{
		for (i = k; i < size; ++i)
		{
			int temp = array[i];
			size_t j;

			for (j = i; j >= k && array[j - k] > temp; j -= k)
			{
				array[j] = array[j - k];
			}

			array[j] = temp;
		}

		print_array(array, size);
		k = (k - 1) / 3;
	}
}

