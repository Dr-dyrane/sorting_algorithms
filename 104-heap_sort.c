#include "sort.h"
#include <stdio.h>

/**
 *swap - Swaps two elements in an array.
 *
 *@a: Pointer to the first element
 *@b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 *heapify - Adjusts the heap to satisfy the heap property.
 *
 *@array: The input array
 *@size: The size of the array
 *@root: The root index of the subtree to heapify
 *@total_size: The total size of the original array
 */
void heapify(int *array, size_t size, int root, size_t total_size)
{
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < (int) size && array[left] > array[largest])
		largest = left;

	if (right < (int) size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 *heap_sort - Sorts an array of integers in ascending order using
 *            the Heap sort algorithm.
 *
 *@array: The array to be sorted
 *@size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (int i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (int i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
