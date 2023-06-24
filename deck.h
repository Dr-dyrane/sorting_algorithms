#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Enumeration of card suits
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a playing card
 * @value: Value of the card (Ace, 2, 3, ..., King)
 * @kind: Suit of the card (SPADE, HEART, CLUB, DIAMOND)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in a deck of cards
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck);
#endif /* DECK_H */

