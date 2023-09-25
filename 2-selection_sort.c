#include "sort.h"

/**
 * swap_integer - swap two integer in an array
 * @j: the first integer to swap
 * @k: the second integer
 */
void swap_integer(int *j, int *k)
{
	int temp;

	temp = *j;
	*j = *k;
	*k = temp;
}

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order
 * @array: an array of integer
 * @size: the size of te array
 * Requirement: print the array after each time you swap two elements
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = array + 1;
		for (y = x + 1; y < size; y++)
			min = (array[y] < *min) ? (array + y) : min;

		if ((array + x) != min)
		{
			swap_integer(array + x, min);
			print_array(array, size);
		}
	}
}
