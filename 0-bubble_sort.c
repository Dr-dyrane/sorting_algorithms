#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *              using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	/*Check if the array is NULL or if it has less than 2 elements */
	/*If so, there's no need to sort, just return */
	if (array == NULL || size < 2)
		return;

	/*Iterate through the array */
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /*Initialize the swapped flag to 0 */

		/*Compare each element with its adjacent element */
		/*If the current element is greater than the next element, swap them */
		/*This moves the largest element to the end of the unsorted portion */
		/* of the array in each iteration */
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{ /*Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/*Set the swapped flag to 1 to indicate that a swap occurred */
				swapped = 1;

				/*Print the current state of the array after the swap */
				print_array(array, size);
			}
		}

		/*If no two elements were swapped in the inner loop, */
		/*it means the array is already sorted and we can break out of the loop */
		if (swapped == 0)
			break;
	}
}
