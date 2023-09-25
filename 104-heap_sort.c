#include "sort.h"

void swap_integer(int *j, int *k);
void max_heappy(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_integer - Swap two integer in an array
 * @j: the first array to swap
 * @k: the second array to swap
 */
void swap_integer(int *j, int *k)
{
	int temp;

	temp = *j;
	*j = *k;
	*k = temp;
}

/**
 * max_heappy - turmn a binary tree into a complete binary heap
 * @array: the array of integers representing a binary tree
 * @size: the size of the array
 * @base: the index of the base row of the tree
 * @root: the root of the binary tree
 */
void max_heappy(int *array, size_t size, size_t base, size_t root)
{
	size_t lt, rt, xxl;

	lt = 2 * root + 1;
	rt = 2 * root + 2;
	xxl = root;

	if (lt < base && array[lt] > array[xxl])
		xxl = lt;
	if (rt < base && array[rt] > array[xxl])
		xxl = rt;

	if (xxl != root)
	{
		swap_integer(array + root, array + xxl);
		print_array(array, size);
		max_heappy(array, size, base, xxl);
	}
}

/**
 * heap_sort - sort an array of integer in ascending
 * order using the heap sort algorithms
 * @array: an array of integers
 * @size: the size of the array
 *
 * Requirement: implements the sift down heap sort
 * algorithms. print the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		max_heappy(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_integer(array, array + x);
		print_array(array, size);
		max_heappy(array, size, x, 0);
	}
}
