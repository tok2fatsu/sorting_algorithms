#include "sort.h"
#include <stdio.h>

/**
 * swap_ar_3 - swaps two array elements and prints the result
 * @array: the array
 * @i: the first index
 * @j: the second index
 */
void swap_ar_3(int *array, size_t i, size_t j)
{
	int temp = array[i];

	if (i == j)
		return;

	array[i] = array[j];
	array[j] = temp;
}

/**
 * bitonic_merge - creates a bitonic sequence by merging ar elements
 * @array: the array
 * @low: lower bound
 * @k: number of elements
 * @dir: direction of sort
 */
void bitonic_merge(int *array, size_t low, size_t k, int dir)
{
	size_t i;

	if (k < 2)
		return;

	for (i = low; i < low + k / 2; i++)
	{
		if (dir == (array[i] > array[i + k / 2]))
			swap_ar_3(array, i, i + k / 2);
	}

	bitonic_merge(array, low, k / 2, dir);
	bitonic_merge(array, low + k / 2, k / 2, dir);
}

/**
 * bitonic_sort_rec - sorts an array using bitonic algorithm
 * @array: the array
 * @size: the size of the array
 * @low: lower bound
 * @k: number of elements
 * @dir: direction of sort
 */
void bitonic_sort_rec(int *array, size_t size, size_t low, size_t k, int dir)
{
	if (k < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", k, size, dir ? "UP" : "DOWN");
	print_array(array + low, k);

	bitonic_sort_rec(array, size, low, k / 2, 1);
	bitonic_sort_rec(array, size, low + k / 2, k / 2, 0);
	bitonic_merge(array, low, k, dir);

	printf("Result [%lu/%lu] (%s):\n", k, size, dir ? "UP" : "DOWN");
	print_array(array + low, k);
}

/**
 * bitonic_sort - sorts an array using the bitonic sorting algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}
