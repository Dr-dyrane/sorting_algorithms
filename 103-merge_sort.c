#include "sort.h"
#include <stdio.h>

/**
 * my_calloc - this is a calloc function
 * @elements: number of elements
 * @size: bit size of each element
 *
 * Return: pointer to memory assignement
 */
void *my_calloc(unsigned int elements, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (elements == 0 || size == 0)
		return ('\0');
	p = malloc(elements * size);
	if (p == '\0')
		return ('\0');
	for (i = 0; i < (elements * size); i++)
		p[i] = '\0';
	return (p);
}

/**
 * merge - make a merge
 * @array: one from start to middle
 * @temp: temp array used in merge, was created outside to
 * optimize reducing the system calls
 * @start: first element position
 * @middle: array middle
 * @end: last element position
 **/
void merge(int *array, int *temp, int start, int middle, int end)
{
	/*  sizes and temp arrays */
	int size_left = middle - start + 1, size_right = end - middle;
	int *array_left, *array_right;
	/* counters */
	int left, right, i = 0;

	array_left = &temp[0];
	array_right = &temp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = array[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = array[middle + 1 + right];
	left = 0, right = 0, i = start;
	/* merging temp arrays into main array*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			array[i] = array_left[left], left++;
		else
			array[i] = array_right[right], right++;
		i++;
	}
	/* merging remaining left array into main array*/
	while (left < size_left)
		array[i] = array_left[left], left++, i++;
	/* merging remaining right array into main array*/
	while (right < size_right)
		array[i] = array_right[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&array[start], left + right);
}

/**
 * merge_sort_recursive - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: array of integers
 * @temp: temp array used in merge, was created outside to
 * optimize reducing the system calls
 * @start: fisrt element position
 * @end: last element position
 *
 * Return: void
 */
void merge_sort_recursive(int *array, int *temp, int start, int end)
{
	int middle;

	middle = (start + end) / 2;
	if ((start + end) % 2 == 0)
		middle--;
	if (middle >= start)
	{
		merge_sort_recursive(array, temp, start, middle);
		merge_sort_recursive(array, temp, middle + 1, end);
		merge(array, temp, start, middle, end);
	}
}

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @size: size of the list
 * @array: array of integers
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = my_calloc(size, sizeof(int));
	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}
