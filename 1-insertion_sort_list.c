#include "sort.h"

/**
 * swap_node - Swaps two nodes in a doubly linked list
 *
 * @node: Pointer to the node to be swapped
 * @list: Double pointer to the head of the list
 *
 * Return: Pointer to the new position of the node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	/* Store the previous and next nodes of the given node */
	listint_t *prev_node, *next_node;

	/* Check if the node is already at the beginning of the list */
	if (!node->prev)
		return (node);

	/* Retrieve the previous and next nodes of the given node */
	prev_node = node->prev;
	next_node = node->next;

	/* Update the previous node's next pointer */
	prev_node->next = next_node;

	/* Check if the node is not at the end of the list */
	if (next_node)
		next_node->prev = prev_node;

	/* Update the node's prev and next pointers */
	node->prev = prev_node->prev;
	node->next = prev_node;

	/* Check if the node is not the new head of the list */
	if (prev_node->prev)
		prev_node->prev->next = node;
	/* Update the head of the list */
	else
		*list = node;

	/* Update the previous node's prev pointer */
	prev_node->prev = node;

	/* Return the new position of the swapped node */
	return (prev_node);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		current = current->next;

		/* Traverse backwards until temp is in the correct position */
		while (temp->prev && temp->n < temp->prev->n)
		{ /* Swap the nodes using the swap_node function */
			temp = swap_node(temp, list);
			/* Print the updated list after swapping */
			print_list(*list);
		}
	}
}
