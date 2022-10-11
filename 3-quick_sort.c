#include "sort.h"

/**
 * swap - swaps two elements of an array and prints the array
 * @array: the array
 * @size: the size of the array
 * @i: the first element to be swapd
 * @j: the second element to be swapd
 */
void swap(int *array, size_t size, int i, int j)
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
 * partition - partitions an array using the Lomuto scheme
 * @array: the array
 * @size: the size of the array
 * @low: the lower bound
 * @high: the higher bound
 *
 * Return: returns the index of the pivot
 */
int partition(int *array, size_t size, int low, int high)
{
	int i = low - 1, j, pvt = high;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= array[pvt])
		{
			i++;
			swap(array, size, i, j);
		}
	}
	swap(array, size, i + 1, pvt);
	return (i + 1);
}

/**
 * quick_sort_Lomuto - quick sort an array using the Lomuto scheme
 * @array: the array
 * @size: the size of the array
 * @low: the lower bound
 * @high: the higher bound
 */
void quick_sort_Lomuto(int *array, size_t size, int low, int high)
{
	int pvt;

	if (low < high)
	{
		pvt = partition(array, size, low, high);
		quick_sort_Lomuto(array, size, low, pvt - 1);
		quick_sort_Lomuto(array, size, pvt + 1, high);
	}
}

/**
 * quick_sort - quick sort an array
 * @array: the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quick_sort_Lomuto(array, size, 0, size - 1);
}
