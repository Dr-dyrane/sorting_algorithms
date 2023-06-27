#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * my_calloc - Allocates memory for an array and sets all elements to zero.
 *
 * @nmemb: The number of elements to allocate
 * @size: The size of each element
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails
 */
void *my_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	size_t i;
	char *tmp;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	tmp = (char *) ptr;
	for (i = 0; i < nmemb * size; i++)
		tmp[i] = 0;

	return (ptr);
}

/**
 * compute_counts - Computes the counts of each element in the input array.
 *
 * @array: The input array
 * @size: The size of the array
 * @max: The maximum element in the array
 *
 * Return: An array of counts
 */
int *compute_counts(int *array, size_t size, int max)
{
	int *counts;
	size_t i;

	counts = my_calloc(max + 1, sizeof(int));
	if (counts == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		counts[array[i]]++;

	return (counts);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                the Counting sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *counts, *output;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counts = compute_counts(array, size, max);
	if (counts == NULL)
		return;
	output = my_calloc(size, sizeof(int));
	if (output == NULL)
	{
		free(counts);
		return;
	}
	printf("%d", counts[0]);
	for (i = 1; i <= max; i++)
	{
		counts[i] += counts[i - 1];
		printf(", %d", counts[i]);
	}
	printf("\n");
	for (i = (int) size - 1; i >= 0; i--)
	{
		output[counts[array[i]] - 1] = array[i];
		counts[array[i]]--;
	}

	for (i = 0; i < (int) size; i++)
		array[i] = output[i];

	free(output);
	free(counts);
}
