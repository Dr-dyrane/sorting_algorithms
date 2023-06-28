#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_max - Finds the maximum value in an array of integers.
 * @array: The array.
 * @size: The size of the array.
 *
 * Return: The maximum value.
 */
int get_max(int *array, int size)
{
	int max_value = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}

/**
 * counting_sort - Performs counting sort on an array of integers based on the
 *                specified digit represented by 'exp'.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The exponent indicating the digit to consider.
 * @output: Array to save the temporary values.
 */
void counting_sort(int *array, size_t size, int exp, int *output)
{
	int count[10] = { 0 };

	int i;

	/* Store count of occurrences in count[] */
	for (i = 0; i < (int) size; i++)
		count[(array[i] / exp) % 10]++;

	/*
	 * Calculate cumulative count.
	 * Change count[i] so that count[i] now contains actual
	 * position of this digit in output[]
	 */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = (int) size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/*
	 * Copy the output array to array[], so that array[] now
	 * contains sorted numbers according to current digit
	 */
	memcpy(array, output, size * sizeof(int));
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *output = malloc(size * sizeof(int));

	if (output == NULL)
		return;

	int maximum = get_max(array, size);
	int exp;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}
