#include "sort.h"
#include <stdio.h>

/**
 *cocktail_sort_list - Sorts a doubly linked list of integers
 *                    in ascending order using Cocktail Shaker sort algorithm
 *
 *@list: Pointer to the pointer to the head of the list
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
		/*Traverse forward */
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				current = swap_node(current->next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;

		/*Traverse backward */
		while (current->prev != NULL)
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

/**
 *swap_node - Swaps a node with its previous one in a doubly linked list
 *
 *@node: Node to be swapped
 *@list: Double pointer to the head of the list
 *
 *Return: Pointer to the new position of the swapped node
 */
listint_t* swap_node(listint_t *node, listint_t **list)
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
	else *list = current;

	return (current);
}
