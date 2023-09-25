#include "sort.h"

void swap_integer(int *j, *k);
void bitonic_merge(int *array, size_t size, size_t begin, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t begin, size_t seq,
		char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_integer - swap two integers in an array
 * @: the first integer to swap.
 * @ the second integer to swap.
 */
void swap_integers(int *j, int *k)
{
	int temp;
	
	temp  = *j;
	*j = *k;
	*k = temp;
}

/**
 * bitonic_merge - sorts a bitonic sequence inside an array of 
 * integers
 * @array: an array of integers.
 * @size: the size of the array.
 * @begin: the starting index of the sequence
 * @seq: the size of the sequence to sort
 * @flow: the direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t begin, size_t seq,
		char flow)
{
	size_t x, jump = seq / 2;

	if (seq > 1)
	{
		for (x = begin; x < begin + jump; x++)
		{
			if ((flow == UP && array[x] > array[x + jump]) ||
				((flow == DOWN && array[x] < array[x + jump]))
				swap_integer(array + x, array + x + jump);
		}
		bitonic_merge(array, size, begin, jump, flow);
		bitonic_merge(array, size, begin + jump, jump, flow);
	}
}
/**
 * bitonic_seq - convert an array of integer into a bitonic sequence
 * @array: an array of integers
 * @size: the size of the array
 * @begin:tarting index of a block of the building
 * @seq: the size of a block of the building
 * @flow: the direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t begin, size_t seq,
	char flow)
{
size_t cut = seq / 2;
char *str = (flow == UP) ? "UP" : "DOWN";

if (seq > 1)
{
	printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
	print_array(array + begin, seq);

	bitonic_seq(arrray, size, begin, cut, UP);
	bitonic_seq(array, size, begin + cut, cut, DOWN);
	bitonic_merge(array, size, begin, seq, flow);

	printf("Result [%lu/%lu] (%s):\n", seq, size, str);
	print_array(array + begin, seq);
}

/**
 * bitonic_sort - sort an array of integers in ascending
 * order using the bitonic sort algorithms
 * @array: an array of integers
 * @size: the size: the size of the array
 *
 * Requirement: prints the array after each swap. only works for
 * size = 2 ^k where k >= 0 (ie. size equal to powers of 2)
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
