#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, index;
	int min_idx, temp, flag = 0;

	if (!array)
		return;

	while (i < size)
	{
		min_idx = i;
		flag = 0;

		/* Find the minimum element in the unsorted part of the array */
		for (index = i + 1; index < size; index++)
		{
			if (array[min_idx] > array[index])
			{
				min_idx = index;
				flag += 1;
			}
		}


		/* Swap the found minimum element with the first element */
		temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;

		if (flag != 0)
			print_array(array, size);

		i++;
	}
}
