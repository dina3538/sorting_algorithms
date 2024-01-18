#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array
 * @size: the size
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, m;

	if (!array || !size)
		return;

	i = 0;
	while (i < size)
	{
		for (m = 0; m < size - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				temp = array[m];
				array[m] = array[m + 1];
				array[m + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
