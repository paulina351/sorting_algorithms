#include "sort.h"

void swap(int *j, int *k);
int lomuto_partition(int *array, int lt, int rt, size_t size);
void lomuto_sort(int *array, int lt, int rt, size_t size);
void quick_sort(int *array, size_t size);

/**
 * quick_sort - sorts an array using quick sort algorith
 * @array:pointer to the array
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	lomuto_sort(array, 0, (int)size - 1, size);
}

/**
 * lomuto_sort - recursive function of the sort algorithms
 * @array: an array of the algorithms
 * @rt: the first
 * @lt: the second
 * @size: size of the array
 * Return: void
 */
void lomuto_sort(int *array, int rt, int lt, size_t size)
{
	int q;

	if (rt >= lt)
		return;

	q = lomuto_partition(array, rt, lt, size);

	if (q - rt > 1)
		lomuto_sort(array, rt, lt, size);
	if (lt - q > 1)
		lomuto_sort(array, q + 1, lt, size);
}

/**
 * lomuto_partition - implementation of lomuto partition
 * @array: the array
 * @rt: the first
 * @lt: the second
 * @size: size of the array
 * Return: new index of the pivot
 */
int lomuto_partition(int *array, int rt, int lt, size_t size)
{
	int pivot = array[lt], x = rt - 1, y, temp;

	for (y = rt; y < lt; y++)
	{
		if (array[y] < pivot)
		{
			++x;
			if (y != x)
			{
				temp = array[y];
				array[y] = array[x];
				array[x] = temp;
				print_array(array, size);
			}
		}
	}
	if (x < lt - 1)
	{
		if (array[x + 1] != array[lt])
		{
			temp = array[lt];
			array[lt] = array[x + 1];
			array[x + 1] = temp;
			print_array(array, size);
		}
		return (x + 1);
	}
	return (lt);
}

/**
 * swap - swap two integer
 * @j: the first number
 * @k: the second number
 */
/*void swap(int *j, int *k)
{
	int temp;

	temp = *j;
	*j = *k;
	*k = temp;
}


 * lomuto_partition - order a subset of an array of integer according to
 * the lomuto partition scheme
 * @array: the array of integer
 * @size: the size of the array of integer.
 * @lt: the beginning index of the sbset to order
 * @rt: the finishing index of the subset to order
 */
/*int lomuto_partition(int *array, size_t size, int lt, int rt)
{
	int pivot = array[lt];
	int j = rt;
	int y;

	for (y = rt; y <= lt; y++)
	{
		if (array[y] <= pivot)
		{
			swap(&array[j], &array[y]);
			if (j != y)
				print_array(array, size);
			j++;
		}
	}
	swap(&array[j], &array[lt]);
	if (j != y)
		print_array(array, size);
	return (j);
}


 * lomuto_sort - implement the quicksort algorithms through recursion
 * @array: an array of integer to sort
 * @size: the size
 * @lt: the beginning
 * @rt: the ending
 *
 * Requirement: using the lomuto partition scheme
 */

/*void lomuto_sort(int *array, size_t size, int lt, int rt)
{
	int pivot;

	if (rt < lt)
	{
		pivot = lomuto_partition(array, rt, lt, size);
		lomuto_sort(array, rt, pivot - 1, size);
		lomuto_sort(array, pivot + 1, lt, size);
	}
}



 * quick_sort - sort an array of integer in ascending
 * order using the quicksort algorithm
 * @array: an array of integer
 * @size: the size of the array
 *
 * Requirement: uses the lomuto partition scheme. prints the array
 */
/*void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}*/
