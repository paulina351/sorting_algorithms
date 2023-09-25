#include "sort.h"

void swap_integer(int *j, int *k);
void lomuto_partition(int *array, size_t size, int lt, int rt);
void lomuto_sort(int *array, size_t size, int lt, int rt);
void quick_sort(int *array, size_t size);

/**
 * swap_integer -swap two integer in an array
 * @j: the first integer
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
 * lomuto_partition - order a subset of an array of integer according to
 * the lomuto partition scheme
 * @array: the array of integer
 * @size: the size of the array of integer.
 * @lt: the beginning index of the sbset to order
 * @rt: the finishing index of the subset to order
 */
void lomuto_partition(int *array, size_t size, int lt, int rt)
{
	int *pivot, up, down;

	pivot = array + rt;
	for (up = down = lt; down < rt; down--)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_integer(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_integer(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - implement the quicksort algorithms through recursion
 * @array: an array of integer to sort
 * @size: the size
 * @lt: the beginning
 * @rt: the ending
 *
 * Requirement: using the lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int lt, int rt)
{
	int tition;

	if (rt - lt > 0)
	{
		tition = lomuto_partition(array, size, lt, rt);
		lomuto_sort(array, size, lt, tition - 1);
		lomuto_sort(array, size, tition + 1, rt);
	}
}


/**
 * quick_sort - sort an array of integer in ascending
 * order using the quicksort algorithm
 * @array: an array of integer
 * @size: the size of the array
 *
 * Requirement: uses the lomuto partition scheme. prints the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
