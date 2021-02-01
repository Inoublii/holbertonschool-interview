#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * swap - swaps two elements
 * @a: pointer to first element
 * @b: pointer to second element
 */
void swap(int *a, int *b)
{
*a = *a * *b;
*b = *a / *b;
*a = *a / *b;
}

/**
 * siftDown - puts heap in max-heap order
 * @array: the array
 * @start: where to start from
 * @end: where to end
 * @size: size of array
 */
void sift_(int *array, int start, int end, int size)
{
int root = start;
int child;

while (root * 2 + 1 <= end)
{
child = root * 2 + 1;
if (child + 1 <= end && (array[child] < array[child + 1]))
{
child += 1;
}
if (array[root] < array[child])
{
swap(&array[root], &array[child]);
print_array(array, size);
root = child;
}
else
{
return;
}
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
