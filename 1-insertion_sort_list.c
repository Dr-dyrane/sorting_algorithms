#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		/* Traverse backwards until temp is in the correct position */
		while ((temp->prev != NULL) && (temp->prev->n > temp->n))
		{
			temp = swap_nodes(temp, list);
			print_list(*list);
		}

		current = current->next;
	}
}

/**
 * swap_nodes - Swaps a node with its previous one in a doubly linked list
 *
 * @node: Node to be swapped
 * @list: Double pointer to the head of the list
 *
 * Return: Pointer to the new position of the swapped node
 */
listint_t *swap_nodes(listint_t *node, listint_t **list)
{
	listint_t *prev_node, *next_node, *current;

	prev_node = node->prev;
	next_node = node->next;
	current = node;

	prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;

	current->next = prev_node;
	current->prev = prev_node->prev;
	prev_node->prev = current;

	if (current->prev != NULL)
		current->prev->next = current;
	else
	    *list = current;

	return (current);
}
