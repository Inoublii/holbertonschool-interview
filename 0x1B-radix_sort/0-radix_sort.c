#include "sort.h"

/**
 * power - calculate power of 10
 * @power: power
 * Return: 10**power
 */

int power(int power)
{
	int i, result = 1;

	for (i = 0; i < power; i++)
		result *= 10;
	return (result);
}


/**
* radix_count - Sort the array depending on exp
* @array: Array to sort
* @size: Size of @array
* @exp: Int to divide array for the digit.
* Return: void
*/

void radix_count(int *array, int size, int exp)
{
int i, *output, count[10] = {0};

output = malloc(sizeof(int) * size);
if (!output)
return;

for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

for (i = 1; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = output[i];
free(output);
}

/**
 * radix_sort - sort an array of integers using radix sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int i, max, digits;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	digits = 1;
	while (max > 0)
	{
		max /= 10;
		radix_count(array, size, digits);
		digits *= 10;
		print_array(array, size);
	}
}

