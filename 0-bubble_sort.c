#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - a function that sorts an array of integers in ascending order
 * @array: the array to sort and print
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t y, z;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (y = 0; y < size; y++)
	{
		for (z = 0; z < (size - y - 1); z++)
		{
			if (array[z] > array[z + 1])
			{
				temp = array[z];
				array[z] = array[z + 1];
				array[z + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
