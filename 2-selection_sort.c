#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order
 * @array: an array of integer
 * @size: the size of te array
 * Requirement: print the array after each time you swap two elements
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t x, y, min;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}

		if (min != x)
		{
			temp = array[x];
			array[x] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
