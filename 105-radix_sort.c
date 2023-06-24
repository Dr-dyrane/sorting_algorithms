#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *get_max - Finds the maximum value in an array of integers.
 *@array: The array.
 *@size: The size of the array.
 *
 *Return: The maximum value.
 */
int get_max(int *array, int size)
{
	int i = 1, max_value = array[0];

	while (i < size)
	{
		if (array[i] > max_value)
			max_value = array[i];
		i++;
	}

	return (max_value);
}

/**
 *counting_sort - Performs counting sort on an array of integers based on the
 *                specified digit represented by 'exp'.
 *@array: The array to be sorted.
 *@size: The size of the array.
 *@exp: The exponent indicating the digit to consider.
 *@output: array to save the temporary values
 */
void counting_sort(int *array, size_t size, int exp, int *output)
{
	int i;
	int count[10] = { 0 };

	/*Store count of occurrences in count[] */
	i = 0;
	while (i < (int) size)
	{
		count[(array[i] / exp) % 10]++;
		i++;
	}
	/*
	 *Calculate cumulative count
	 *Change count[i] so that count[i] now contains actual
	 *position of this digit in output[]
	 */
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}

	/*Build the output array */
	i = size - 1;
	while (i >= 0)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
		i--;
	}
	/*
	 *Copy the output array to array[], so that array[] now
	 *contains sorted numbers according to current digit
	 */
	i = 0;
	while (i < (int) size)
	{
		array[i] = output[i];
		i++;
	}
}

/**
 *radix_sort - The main function to that sorts arr[]
 *of size n using Radix Sort
 *@array: array
 *@size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	/*Find the maximum number to know number of digits */
	int exp = 1, maximum = 0;
	int *output = '\0';

	if (array == '\0' || size < 2)
		return;

	maximum = get_max(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;
	/*
	 *Do counting sort for every digit. Note that instead
	 *of passing digit number, exp is passed. exp is 10^i
	 *where i is current digit number
	 */
	while (maximum / exp > 0)
	{
		counting_sort(array, size, exp, output);
		print_array(array, size);
		exp *= 10;
	}

	free(output);
}
