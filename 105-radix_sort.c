#include "sort.h"
#include <stdlib.h>

/**
 * max_ar - returns the maximum element in the array
 * @array: the array
 * @size: the size of the array
 *
 * Return: returns the maximum value
 */
int max_ar(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * mod_counting_sort - counting sort implementation
 * @array: the array to be sorted
 * @size: the size of the array
 * @factor: the tenth factor to get the digit
 */
void mod_counting_sort(int *array, size_t size, int factor)
{
	int *count_ary, *output;
	size_t j;

	count_ary = malloc(sizeof(int) * 10);
	if (count_ary == NULL)
		return;
	for (j = 0; j < 10; j++)
		count_ary[j] = 0;

	for (j = 0; j < size; j++)
		count_ary[(array[j] / factor) % 10]++;
	for (j = 1; j < 10; j++)
		count_ary[j] += count_ary[j - 1];

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count_ary);
		return;
	}
	for (j = size - 1; (int)j >= 0; j--)
	{
		output[count_ary[(array[j] / factor) % 10] - 1] = array[j];
		count_ary[(array[j] / factor) % 10]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(count_ary);
	free(output);
}

/**
 * radix_sort - sorts an array using the radix sorting algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, factor = 1;

	if (array == NULL || size < 2)
		return;

	max = max_ar(array, size);

	while (max / factor > 0)
	{
		mod_counting_sort(array, size, factor);
		print_array(array, size);
		factor *= 10;
	}
}
