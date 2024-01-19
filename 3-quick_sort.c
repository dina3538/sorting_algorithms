#include "sort.h"

/**
 * _swap - swap elements
 * @array: the int
 * @size: the size
 * @x: first addr
 * @y: second addr
 * Return: void
 */

void _swap(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}

/**
 * _lemouto - partition
 * @array: the ints
 * @size: the size
 * @less: less index
 * @hig: hig index
 * Return: size_t
 */
size_t _lemouto(int *array, size_t size, ssize_t less, ssize_t hig)
{
	int x, y, piv = array[hig];

	for (x = y = less; y < hig; y++)
		if (array[y] < piv)
			_swap(array, size, &array[y], &array[x++]);
	_swap(array, size, &array[x], &array[hig]);

	return (x);
}

/**
 * _quick - quick sort by lemouto
 * @array: the ints
 * @size: the size
 * @less: less indx
 * @hig: hig indx
 * Return: void
 */
 void _quick(int *array, size_t size, ssize_t less, ssize_t hig)
{
	if (less < hig)
	{
		size_t d = _lemouto(array, size, less, hig);

		_quick(array, size, less, d - 1);
		_quick(array, size, d + 1, hig);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * @array: the int to sort
 * @size: size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	_quick(array, size, 0, size - 1);
}
