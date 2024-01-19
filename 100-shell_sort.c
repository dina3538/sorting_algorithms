#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval;
	size_t i;
	
	if (array == NULL || size < 2)
		return;

	interval = 1;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; ++i)
		{
			int temp = array[i];
			size_t j;

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}

			array[j] = temp;
		}

		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}

