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
 * merge - Merges two subarrays into one sorted array.
 *
 * @array: The input array
 * @left: Pointer to the left subarray
 * @l_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @r_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
	size_t i, j, k;
	int *merged;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_size);
	printf("[right]: ");
	print_array(right, r_size);

	merged = my_calloc(l_size + r_size, sizeof(int));
	if (merged == NULL)
		return;

	i = 0;
	j = 0;
	k = 0;

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}

	while (i < l_size)
		merged[k++] = left[i++];

	while (j < r_size)
		merged[k++] = right[j++];

	for (i = 0; i < l_size + r_size; i++)
		array[i] = merged[i];

	printf("[Done]: ");
	print_array(array, l_size + r_size);

	free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *             the Merge sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	if (size > 1)
	{
		mid = size / 2;
		left = array;
		right = array + mid;

		merge_sort(left, mid);
		merge_sort(right, size - mid);

		merge(array, left, mid, right, size - mid);
	}
}
