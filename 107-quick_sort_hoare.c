#include "sort.h"

void swap_integer(int *j, int *k);
int hoare_partition(int *array, size_t size, int lt, int rt);
void hoare_sort(int *array, size_t size, int lt, int rt);
void quick__sort_hoare(int *array, size_t size);

/**
 * swap_integer - swap two integer of the array
 * j: the first integer to swap
 * @k: the second integer to swap.
 */
void swap_integer(int *j, int *k)
{
	int temp;

	temp = *j;
	*j = *k;
	*k = temp;
}

/**
 * hoare_partition - order a subset of an array of integer
 * according to the hoare partition scheme
 * @array: the array of integers
 * @size: the size of the integer
 * @lt: the starting index of the subset to order
 * @rt: the ending index of the subset to order
 *
 * Return: the final partition index.
 *
 * Description: the uses the last element of the partition as the pivot
 * print the array after each swap of two elements
 */
int hoare_partition(int *array, size_t size, int lt, int rt)
{
	int pivot, up, down;

	pivot = array[rt];

	for (up = lt - 1, down = rt + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_integer(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - implement the quicksort algorithms through recursion
 * @array: an array of integer
 * @size: the size of the array
 * @lt: the starting index of the array
 * @rt: the ending index
 *
 * Requirement: uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int lt, int rt)
{
	int tition;

	if (rt - lt > 0)
	{
		tition = hoare_partition(array, size, lt, rt);
		hoare_sort(array, size, lt, tition - 1);
		hoare_sort(array, size, tition, rt);
	}
}

/**
 * quick_sort_hoare - sort an array of integer in ascending
 * order using the quicksort algorithms
 * @array: the array of integers
 * @size: the size of the array
 *
 * Requirement: uses the hoare partition scheme.
 * print the array after each swap of two integers.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
