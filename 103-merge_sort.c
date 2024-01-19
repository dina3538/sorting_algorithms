#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);

/**
 *  * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 *   * @array: The array to be sorted
 *    * @size: Number of elements in @array
 *     */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	/* Allocate temporary array for merging */
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	/* Call the recursive merge sort function */
	merge_sort_recursive(array, temp, 0, size - 1);

	/* Free the temporary array */
	free(temp);
}

/**
 *  * merge_sort_recursive - Recursively divides and merges the array
 *   * @array: The array to be sorted
 *    * @temp: Temporary array for merging
 *     * @left: Left index of the subarray
 *      * @right: Right index of the subarray
 *       */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left < right)
	{
		/* Find the middle point to divide the array into two halves */
		size_t mid = left + (right - left) / 2;

		/* Recursively sort the first and second halves */
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid + 1, right);

		/* Merge the sorted halves */
		merge(array, temp, left, mid, right);
	}
}

/**
 *  * merge - Merges two subarrays into a sorted array
 *   * @array: The array to be sorted
 *    * @temp: Temporary array for merging
 *     * @left: Left index of the subarray
 *      * @mid: Middle index of the subarray
 *       * @right: Right index of the subarray
 *        */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid + 1;
	size_t k = left;

	/* Copy data to temporary arrays temp[] */
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];

		}
	}
}	
