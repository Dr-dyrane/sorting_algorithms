#include "sort.h"

/**
 *shell_sort - Sorts an array of integers in ascending order
 *             using the Shell sort algorithm with Knuth sequence
 *
 *@array: Pointer to the array to be sorted
 *@size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/*Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/*Perform Shell sort with decreasing gap */
	while (gap > 0)
	{
		/*Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/*Shift elements that are greater than temp */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			/*Place temp in its correct position */
			array[j] = temp;
		}

		/*Print the current state of the array */
		print_array(array, size);

		/*Update the gap */
		gap = (gap - 1) / 3;
	}
}