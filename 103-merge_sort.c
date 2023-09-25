#include "sort.h"

void merge_parray(int *prearr, int *buf, size_t fro, size_t mid, size_t back);
void merge_sort_recursive(int *prearr, int *buf, size_t fro, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_parray - Sort a subarray of integers
 * @parray: A subarray of an array of integer
 * @buf: a buffer
 * @fro: the front index of the array
 * @mid: the middle index of the array
 * @back: the back index
 */
void merge_parray(int *parray, int *buf, size_t fro, size_t mid, size_t back)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(parray + fro, mid - fro);

	printf("[right]: ");
	print_array(parray + mid, back - mid);

	for (x = fro, y = mid; x < mid && y < back; z++)
		buf[z] = (parray[x] < parray[y]) ? parray[x++] : parray[y++];
	for (; x < mid; x++)
		buf[z++] = parray[x];
	for (; y < back; y++)
		buf[z++] = parray[y];
	for (x = fro, z = 0; x < back; x++)
		parray[x] = buf[z++];

	printf("[Done]: ");
	print_array(parray + fro, back - fro);
}

/**
 * merge_sort_recursive - implements the merge sort algorithm through recursion
 * @parray: the sub array of integer to sort
 * @buf: a buffer to store the sorted result
 * @fro: the front index of the array
 * @back: the back index of the parray
 */
void merge_sort_recursion(int *parray, int *buf, size_t fro, size_t back)
{
	size_t mid;

	if (back - fro > 1)
	{
		mid = fro + (back - fro) / 2;
		merge_sort_recursive(parray, buf, fro, mid);
		merge_sort_recursive(parray, buf, mid, back);
		merge_parray(parray, buf, fro, mid, back);
	}
}

/**
 * merge_sort - sort an array of intergers in ascending order using the merge sort algorithms
 * @array: An array of integer
 * @size: the size of the array
 *
 * Requirements: implements the top_down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL ||  size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recursive(array, buf, 0, size);

	free(buf);
}
