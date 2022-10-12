#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array_limit - prints array between bounds
 * @array: the array
 * @low: lower limit
 * @high: upper limit
 */
void print_array_limit(int *array, size_t low, size_t high)
{
	size_t a;

	a = low;
	while (array && a < high)
	{
		if (a > low)
			printf(", ");
		printf("%d", array[a]);
		++a;
	}
	printf("\n");
}

/**
 * merge_arry - merges the two halfs of a merge sort sub arrays
 * @array: the array
 * @cpy_array: copy of the array
 * @low: lower bound
 * @m: middle bound
 * @high: upper bound
 */
void merge_arry(int *array, int *cpy_array, size_t low, size_t m, size_t high)
{
	size_t c, a = low, b = m;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_limit(array, low, m);
	printf("[right]: ");
	print_array_limit(array, m, high);

	for (c = low; c < high; c++)
	{
		if (a < m && (b >= high || array[a] <= array[b]))
		{
			cpy_array[c] = array[a];
			a++;
		}
		else
		{
			cpy_array[c] = array[b];
			b++;
		}
	}
	printf("[Done]: ");
	print_array_limit(cpy_array, low, high);
}

/**
 * merge_sort_rec - runs a merge sort recursively
 * @cpy_array: copy of the array
 * @array: the array
 * @low: lower bound
 * @high: upper bound
 */
void merge_sort_rec(int *cpy_array, int *array, size_t low, size_t high)
{
	size_t m;

	if (high - low <= 1)
		return;

	m = (low + high) / 2;

	merge_sort_rec(array, cpy_array, low, m);
	merge_sort_rec(array, cpy_array, m, high);
	merge_arry(cpy_array, array, low, m, high);
}

/**
 * merge_sort - sorts an array using merge sort algo impl
 * @array: the array
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *cpy_array;
	size_t a;

	if (array == NULL || size < 2)
		return;

	cpy_array = malloc(sizeof(int) * size);
	if (cpy_array == NULL)
		return;
	for (a = 0; a < size; a++)
		cpy_array[a] = array[a];

	merge_sort_rec(cpy_array, array, 0, size);
	free(cpy_array);
}
