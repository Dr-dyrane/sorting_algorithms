#include <stdio.h>
#include "sort.h"

/**
* swap - Swaps the positions of two elements into an array.
* @array: Pointer to the array.
* @item1: array element.
* @item2: array element.
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * hoare_partition - hoare partition scheme for  quicksort.
 * @array: Pointer to the array.
 * @start: Starting index of the partition.
 * @end: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: The index of the pivot after partitioning.
 *
 * Description: This function selects the pivot and partitions the array
 *              into two sub-arrays using the Hoare partition scheme.
 *              It returns the index of the pivot after partitioning.
 *              It also prints the array after each swap operation.
 */
int hoare_partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int current = start - 1;
	int finder = end + 1;

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);

		do {
			finder--;
		} while (array[finder] > pivot);

		if (current >= finder)
			return (current);

		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort.
 * @array: Pointer to the array to be sorted.
 * @start: Starting index of the array/sub-array.
 * @end: Ending index of the array/sub-array.
 * @size: Size of the array.
 *
 * Description: This function recursively performs the quicksort algorithm
 *              using the Hoare partition scheme. It selects a pivot,
 *              partitions the array, and recursively sorts the sub-arrays.
 */
void quick_sort_recursive(int *array, ssize_t start, ssize_t end, int size)
{
	ssize_t position = 0;

	if (start < end)
	{
		position = hoare_partition(array, start, end, size);
		quick_sort_recursive(array, start, position - 1, size);
		quick_sort_recursive(array, position, end, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers using quicksort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the quicksort algorithm with the Hoare partition scheme.
 *              If the array is NULL or has less than 2 elements, no sorting
 *              is performed.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
