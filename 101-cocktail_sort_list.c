#include "sort.h"
#include <stdio.h>

/**
 * swap_node - Swaps two nodes in a doubly linked list.
 *
 * @list: Double pointer to the head of the linked list
 * @node: Node to be swapped
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *temp = node->prev, *current = node;

	temp->next = current->next;
	if (current->next)
		current->next->prev = temp;
	current->next = temp;
	current->prev = temp->prev;
	temp->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order
 *                     using the Cocktail shaker sort algorithm.
 *
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	current = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				current = swap_node(current->next, list);
				swapped = 1;
				print_list(*list);
			}
			current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				current = swap_node(current, list);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
