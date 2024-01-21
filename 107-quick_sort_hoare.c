#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

size_t hoare_partition(int *array, size_t low, size_t high, size_t size) {
	int pivot = array[high];
	size_t i = low - 1;
	size_t j = high + 1;

	while (1) {
		while (++i < size && array[i] < pivot);
		while (j > 0 && array[--j] > pivot);

		if (i >= j) {
			return j;
		}

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

void quick_sort_recursive(int *array, size_t low, size_t high, size_t size) {
	if (low < high) {
		size_t partition_index = hoare_partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_index, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

void quick_sort_hoare(int *array, size_t size)
{
	size_t low = 0;
	size_t high = size - 1;

	if (array == NULL || size < 2) {
		return;
	}


	quick_sort_recursive(array, low, high, size);
}

