#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail Shaker sort algorithm
 *
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		/* Traverse forward */
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;
		/* Traverse backward */
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_node(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
