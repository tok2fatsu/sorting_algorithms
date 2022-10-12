#include "sort.h"

/**
 * shell_sort - shell sort algorithm using Knuth Sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */


void shell_sort(int *array, size_t size)
{
	size_t n = 1, a, b;
	int temp;

	while (n < size)
		n = n * 3 + 1;

	for (n /= 3; n >= 1; n /= 3)
	{
		for (a = n; a < size; a++)
		{
			temp = array[a];
			for (b = a; (b >= n) && (array[b - n] > temp); b -= n)
				array[b] = array[b - n];
			array[b] = temp;
		}
		print_array(array, size);
	}
}
