#include "sort.h"

/**
 * swap_integer - swap two array of integer
 * @j: the first array
 * @k: the second array
 */

void swap_integer(int *j, int *k)
{
	int temp;

	temp = *j;
	*j = *k;
	*k = temp;
}

/**
 * shell_sort - sort an array of integer in ascending
 * order using the shell sort algorithm
 * @array: an array of integer
 * @size: the size of the array
 * Requirement: to use the sequence of interval also known as knuth
 * sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, x, y;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap/= 3)
	{
		for (x = gap; 1 < size; x++)
		{
			y = x;
			while (y >= gap && array[y - gap] > array[y])
			{
				swap_integer(array + y, array + (y - gap));
				y -= gap;
			}
		}
		print_array(array, size);
	}
}
