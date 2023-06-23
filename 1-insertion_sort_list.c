#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		/* Traverse backwards until temp is in the correct position */
		while ((current->prev) && (current->prev->n > current->n))
		{
			current = swap_node(current, list);
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
