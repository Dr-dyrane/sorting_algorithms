#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                    in ascending order using Cocktail Shaker sort algorithm
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

/**
 * swap_node - Swaps a node with its previous one in a doubly linked list
 *
 * @node: Node to be swapped
 * @list: Double pointer to the head of the list
 *
 * Return: Pointer to the new position of the swapped node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev, *current = node;

	prev_node->next = current->next;
	if (current->next)
		current->next->prev = prev_node;

	current->next = prev_node;
	current->prev = prev_node->prev;
	prev_node->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
	    *list = current;

	return (current);
}
