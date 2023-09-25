#include "sort.h"

int get_max(int *array, int size);
int radix_counting_sort(int *array, size_t size, int sign, int *buf);
void radix_sort(int *array, size_t size);

/**
 * get_max - get the maximum value in an array of integers
 * @array: an array of integer
 * @size: the size of the array
 *
 * Return: the maximum of the array
 */
int get_max(int *array, int size)
{
	int max, x;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}

	return (max);
}

/**
 * radix_counting_sort - sort the significant digits of an array of integers
 * in acending order using the counting sort algorithm.
 * @array: the array of integer
 * @size: the size of the array
 * @sign: the significant digit to sort on
 * @buf: a buffer to store the sorted array
 */
void radix_counting_sort(int *array, size_t size, int sign, int *buf)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	size_t x;

	for (x = 0; x < size; x++)
		count[(array[x] / sign) % 10] += 1;

	for (x = 0; x < 10; x++)
		count[x] += count[x - 1];

	for (x = size - 1; (int)x >= 0; x--)
	{
		buf[count[(array[x] / sign) % 10] - 1] = array[x];
		count[(array[x] / sign) % 10] -= 1;
	}

	for (x = 0; x < size; x++)
		array[x] = buf[x];
}

/**
 * radix_sort - sort an array of integer in ascending
 * order using the radix sort algorithms
 * @array: the array of integer
 * @size: the size of the array
 * Requirement: Implements the LSD radix sort algorithms.
 * prints the array after each significant digit increases
 */
void radix_sort(int *array, size_t size)
{
	int max, sign, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	max = get_max(array, size);

	for (sign = 1; max / sign > 0; sign *= 10)
	{
		radix_counting_sort(array, size, sign, buf);
		print_array(array, size);
	}

	free(buf);
}
