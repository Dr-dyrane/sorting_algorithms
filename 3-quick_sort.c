#include "sort.h"

/**
* swap - the pivot element with the element at the partition index
* @array: array
* @item1: array element
* @item2: array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Pointer to the array to be sorted
 * @first: First array element
 * @last: Last array element
 * @size: Size array
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	/* Choose the last element as the pivot */
	int pivot = array[last];

	/* Initialize the partition index */
	ssize_t current = first, finder;

	/* Iterate over the partition */
	for (finder = first; finder < last; finder++)
	{
		/* If the current element is less than the pivot */
		/* swap it with the element at the partition index and increment the index */
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	/* Swap the pivot element with the element at the partition index */
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}

	/* Return the index of the pivot element */
	return (current);
}

/**
 * quicksort_recursive - Recursive helper function for Quick sort
 * @array: Pointer to the array to be sorted
 * @first: First array element
 * @last: Last array element
 * @size: Array size
 */
void quicksort_recursive(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		/* Partition the array and get the pivot index */
		position = lomuto_partition(array, first, last, size);

		/* Recursively sort the left and right partitions */
		quicksort_recursive(array, first, position - 1, size);
		quicksort_recursive(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}
