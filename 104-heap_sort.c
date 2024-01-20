#include "sort.h"
#define father(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 * _swap_ - swap elements
 * @array: the int
 * @size: the size
 * @x: first addr
 * @y: second addr
 * Return: void
 */
void _swap_(int *array, size_t size, int *x, int *y)
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
 * _siftdown - the siftdown part
 * @array: array of ints
 * @begin: first indx
 * @end: last indx
 * @size: array size
 */

void _siftdown(int *array, size_t begin, size_t end, size_t size)
{
	size_t home = begin, _swap, child;

	while(leftchild(home) <= end)
	{
		child = leftchild(home);
		_swap = home;
		if (array[_swap] < array[child])
			_swap = child;
		if (child + 1 <= end &&
			array[_swap] <= array[child + 1])
			_swap = child + 1;
		if (_swap == home)
			return;
		_swap_(array, size, &array[home], &array[_swap]);
		home = _swap;
	}
}

/**
 * join - put the heap 
 * @array: array of ints
 * @size: the size
 */

void join(int *array, size_t size)
{
	size_t begin;

	begin = father(size - 1);
	while (begin >= 0)
	{
		_siftdown(array, begin, size - 1, size);
		begin--;
	}
}

/**
 * heap_sort - heap sort
 * @array: array of ints
 * @size: the size
 */

void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	join(array, size);
	end = size - 1;
	while (end > 0)
	{
		_swap_(array, size, &array[end], &array[0]);
		end--;
		_siftdown(array, 0, end, size);
	}
}
