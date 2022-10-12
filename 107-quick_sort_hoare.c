#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ar_2 - swaps two elements of an array and prints the array
 * @array: the array
 * @size: the size of the array
 * @i: the first element to be swapd
 * @j: the second element to be swapd
 */
void swap_ar_2(int *array, size_t size, int i, int j)
{
	int temp;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * hoare_partition - partitions an array using the Hoare scheme
 * @array: the array
 * @size: the size of the array
 * @low: the lower bound
 * @high: the higher bound
 *
 * Return: returns the index of the pivot
 */
int hoare_partition(int *array, ssize_t size, int low, int high)
{
	ssize_t i = low - 1, j = high + 1;
	int pvt = array[high];

	while (1)
	{
		while (array[++i] < pvt)
		;
		while (array[--j] > pvt)
		;

		if (i >= j)
			return (i);

		swap_ar_2(array, size, i, j);
	}
}

/**
 * quick_sort_2 - quick sort an array using the Lomuto scheme
 * @array: the array
 * @size: the size of the array
 * @low: the lower bound
 * @high: the higher bound
 */
void quick_sort_2(int *array, size_t size, int low, int high)
{
	int pvt;

	if (low < high)
	{
		pvt = hoare_partition(array, size, low, high);
		quick_sort_2(array, size, low, pvt - 1);
		quick_sort_2(array, size, pvt, high);
	}
}

/**
 * quick_sort_hoare - quick sort an array
 * @array: the array
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quick_sort_2(array, size, 0, size - 1);
}
