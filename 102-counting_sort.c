#include "sort.h"
#include <stdlib.h>

/**
 * max - returns the maximum element in the array
 * @array: the array
 * @size: the size of the array
 *
 * Return: returns the maximum value
 */
int max(int *array, size_t size)
{
	int max = array[0];
	size_t a;

	for (a = 0; a < size; a++)
	{
		if (max < array[a])
			max = array[a];
	}
	return (max);
}

/**
 * counting_sort - counting sort implementation
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t max_val;
	int *count_array, *output_array;
	size_t b;

	if (array == NULL || size < 2)
		return;
	max_val = max(array, size);
	count_array = malloc(sizeof(int) * (max_val + 1));
	if (count_array == NULL)
		return;

	for (b = 0; b <= max_val; b++)
		count_array[b] = 0;
	for (b = 0; b < size; b++)
		count_array[array[b]]++;
	for (b = 1; b < (max_val + 1); b++)
		count_array[b] += count_array[b - 1];

	print_array(count_array, max_val + 1);

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}
	for (b = 0; b < size; b++)
	{
		output_array[count_array[array[b]] - 1] = array[b];
		count_array[array[b]]--;
	}

	for (b = 0; b < size; b++)
		array[b] = output_array[b];

	free(count_array);
	free(output_array);
}
