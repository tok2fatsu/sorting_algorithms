#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
 * swap - a function to flip through @temp
 * @x: first temporary number
 * @y: sevond temporary number for @x to be replaced with.
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - A function to implement bubble sort
 * @array: points to array to be sorted.
 * @size: number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int long i, j;

	for (i = 0; i < size - 1; i++)

		/* Last i elements are already in place */
	for (j = 0; j < size - i - 1; j++)
		if (array[j] > array[j + 1])
			swap(&array[j], &array[j + 1]);
}
