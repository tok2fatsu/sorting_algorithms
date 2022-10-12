#include "sort.h"

/**
 * swap_ar - swaps two array elements and prints the result
 * @array: the array
 * @size: the size of the array
 * @i: the first index
 * @j: the second index
 */
void swap_ar(int *array, size_t size, size_t a, size_t b)
{
	int temp = array[b];

	if (a == b)
		return;

	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}

/**
 * heapify - heapifies the given array
 * @array: the array
 * @size: the size of the array
 * @start: the start 1 based index
 * @end: the end 1 based index
 */
void heapify(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, swap_idx;

	while (2 * root <= end)
	{
		swap_idx = root;
		if (array[swap_idx - 1] < array[2 * root - 1])
			swap_idx = 2 * root;
		if (2 * root + 1 <= end && array[swap_idx - 1] < array[2 * root + 1 - 1])
			swap_idx = 2 * root + 1;

		if (swap_idx == root)
			return;

		swap_ar(array, size, swap_idx - 1, root - 1);
		root = swap_idx;
	}
}

/**
 * build_max_heap - builds a max heap
 * @array: the array
 * @size: the size of the array
 */
void build_max_heap(int *array, size_t size)
{
	size_t start = size / 2;

	while (start >= 1)
	{
		heapify(array, size, start, size);
		start--;
	}
}

/**
 * heap_sort - sorts the given array using the heap sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t a;

	if (array == NULL || size < 2)
		return;
	build_max_heap(array, size);
	for (a = size; a >= 1; )
	{
		swap_ar(array, size, 0, a - 1);
		heapify(array, size, 1, --a);
	}
}
