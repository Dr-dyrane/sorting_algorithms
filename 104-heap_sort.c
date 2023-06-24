#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sift_down - Repair the heap by sifting down an element at given index.
 * @array: The array to be sorted.
 * @start: The index of the element to sift down.
 * @end: The index of the last element in the heap.
 *
 * Return: None.
 */
void sift_down(int *array, size_t start, size_t end)
{
	size_t root = start;

	while (2 * root + 1 <= end)
	{
		size_t child = 2 * root + 1; /* Left child */
		size_t swap = root;

		if (child < end && array[child] < array[child + 1])
			child++; /* Choose the largest child */

		if (array[root] < array[child])
		{
			swap = child;
			/* Swap root and the largest child */
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, end + 1);
			root = swap;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: None.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, i, size - 1);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap root (maximum element) with the last element */
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1);
	}
}
