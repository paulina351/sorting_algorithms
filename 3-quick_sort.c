#include "sort.h"

void lomuto_partition(int *array, size_t size, int lt, int rt);
void lomuto_sort(int *array, size_t size, int lt, int rt);
void quick_sort(int *array, size_t size);

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
	int pivot = array[rt];
	int x = lt - 1;
	int y, temp;

	for (y = lt; y <= rt - 1; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			temp = array[x];
			array[x] = array[y];
			array[y] = temp;
			if (x != y)
				print_array(array, size);
		}
	}
	temp = array[x + 1];
	array[x + 1] = array[rt];
	array[rt] = temp;
	if (x + 1 != rt)
		print_array(array, size);
	return (x + 1);
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
	int pivot;

	if (rt < lt)
	{
		pivot = lomuto_partition(array, rt, lt, size);
		lomuto_sort(array, lt, pivot - 1, size);
		lomuto_sort(array, pivot + 1, rt, size);
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
