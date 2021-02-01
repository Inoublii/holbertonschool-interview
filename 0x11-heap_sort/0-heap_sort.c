#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_ - Repair the heap whose root element is at index start.
 *
 * @array: the array of the elements.
 * @size: the size of the array.
 * @start: the first index of the heap.
 * @end: the last index of the heap.
*/
void sift_(int *array, int size, int start, int end)
{
	int change, child, root, left, right;

	root = start;

	while (((2 * root) + 1) <= end)
	{
		left = 2 * root + 1;
		child = left;
		change = root;

		if (array[change] < array[child])
			change = child;
		right = 2 * root + 2;
		if (right <= end && array[change] < array[right])
			change = right;
		if (change != root)
		{
		int tmp;

		tmp = array[root];
		array[root] = array[change];
		array[change] = tmp;
		print_array(array, size);
		root = change;
		}
		else
			return;
	}
}
/**
*	heap_sort - heap sort in ascending order
 *
 *	@array: Array to be sorted
 *	@size: Array size
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;
	long beg = (size - 2) / 2;

	if (size < 2)
		return;

	while (beg >= 0)
		sift_(array, size, beg--, size - 1);

	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		sift_(array, size, 0, --end);
	}
}
