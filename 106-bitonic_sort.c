#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in the array based on the specified order.
 * @array: The array.
 * @item1: Index of the first element.
 * @item2: Index of the second element.
 * @order: 1 for ascending order, 0 for descending order.
 * Description: If the order is 1 (ascending) and the first element is greater
 * than the second element, or if the order is 0 (descending) and the first
 * element is smaller than the second element, the elements are swapped.
 */
void swap(int array[], int item1, int item2, int order)
{
	int temp;

	if (order == (array[item1] > array[item2]))
	{
		temp = array[item1];
		array[item1] = array[item2];
		array[item2] = temp;
	}
}

/**
 * merge - Recursively sorts bitonic sequences in both orders.
 * @array: The array.
 * @start: Index of the first element.
 * @elements: Number of elements.
 * @order: 1 for ascending order, 0 for descending order.
 * Description: Divides the array into two parts based on the middle index.
 * Swaps the elements in the first part with their corresponding elements in
 * the second part based on the order. Recursively sorts the two parts.
 */
void merge(int array[], int start, int elements, int order)
{
	int middle, index;

	if (elements > 1)
	{
		middle = elements / 2;
		for (index = start; index < start + middle; index++)
			swap(array, index, index + middle, order);
		merge(array, start, middle, order);
		merge(array, start + middle, middle, order);
	}
}

/**
 * bit_recursive - Recursive function to perform Bitonic sort.
 * @array: The array.
 * @start: Index of the first element.
 * @elements: Number of elements.
 * @order: 1 for ascending order, 0 for descending order.
 * @size: Length of the array.
 * Description: Recursively divides the array into two parts and sorts them
 * in ascending or descending order based on the order parameter. Then, merges
 * the two parts to obtain a sorted bitonic sequence.
 */
void bit_recursive(int array[], int start, int elements, int order, int size)
{
	int middle;

	if (elements > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", elements, size);
			print_array(&array[start], elements);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", elements, size);
			print_array(&array[start], elements);
		}
		middle = elements / 2;
		bit_recursive(array, start, middle, 1, size);
		bit_recursive(array, start + middle, middle, 0, size);
		merge(array, start, elements, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", elements, size);
			print_array(&array[start], elements);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", elements, size);
			print_array(&array[start], elements);
		}
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order.
 * Using the Bitcoin sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Description: Performs the Bitonic sort algorithm on the given array.
 * If the array is NULL or has less than 2 elements, the function returns
 * immediately. Otherwise, it calls the recursive function to perform the sort.
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;

	bit_recursive(array, 0, size, order, size);
}
