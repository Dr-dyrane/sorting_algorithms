#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - Adjusts the heap to satisfy the heap property.
 *
 * @array: The input array
 * @size: The size of the array
 * @root: The root index of the subtree to heapify
 * @total_size: The total size of the original array
 */
void heapify(int *array, size_t size, int root, size_t total_size)
{
	int largest = root;		 /* Initialize largest as root*/
	int left = 2 * root + 1;	 /* left = (root << 1) + 1*/
	int right = 2 * root + 2; /* right = (root + 1) << 1*/

	/* See if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * See if right child of root exists and is greater than
     *the largest so far
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if needed*/
	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *             the Heap sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	/**
	 * Start from bottommost and rightmost internal mode and heapify all
     * internal modes in bottom up way
	 */
	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		heapify(array, size, i, size);

	/**
	* Repeat following steps while heap size is greater than 1.
    * The last element in max heap will be the minimum element
	*/
	for (i = (size - 1); i > 0; --i)
	{
		/**
		* The largest item in Heap is stored at the root. Replace
		*it with the last item of the heap followed by reducing the
		*size of heap by 1.
		*/
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Finally, heapify the root of tree.*/
		heapify(array, size, 0, i);
	}
}
