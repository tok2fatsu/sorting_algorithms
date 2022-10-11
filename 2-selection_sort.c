#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, min_arr;
	int temp;

	if (array != NULL && size > 1)
	{
		for (a = 0; a < size; a++)
		{
			min_arr = a;
			for (b = a + 1; b < size; b++)
			{
				if (array[min_arr] > array[b])
					min_arr = b;
			}
			if (min_arr != a)
			{
				temp = array[min_arr];
				array[min_arr] = array[a];
				array[a] = temp;
				print_array(array, size);
			}
		}
	}
}
