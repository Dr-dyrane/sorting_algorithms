#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * card_cmp - Comparator function for card_t structures
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * Return: Negative value if card1 is less than card2,
 * positive value if card1 is greater than card2, 0 if they are equal
 */
int card_cmp(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **) card1;
	const card_t *c2 = *(const card_t **) card2;

	int value_cmp = strcmp(c1->value, c2->value);

	if (value_cmp != 0)
		return (value_cmp);

	return (c1->kind - c2->kind);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	card_t *cards[52];
	deck_node_t *node = *deck;

	for (i = 0; i < 52; i++)
	{
		cards[i] = (card_t *) node->card;
		node = node->next;
	}

	qsort(cards, 52, sizeof(card_t *), card_cmp);

	node = *deck;
	for (i = 0; i < 52; i++)
	{
		node->card = cards[i];
		node = node->next;
	}
}
