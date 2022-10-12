#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_card_value - Get the value object
 * @name: name of the card
 *
 * Return: the value of the card
 */
int get_card_value(const char *name)
{
	if (strcmp(name, "Ace") == 0)
		return (0);
	else if (strcmp(name, "Jack") == 0)
		return (11);
	else if (strcmp(name, "Queen") == 0)
		return (12);
	else if (strcmp(name, "King") == 0)
		return (13);

	return (atoi(name));
}

/**
 * cmp_deck_func - a deck comparision function
 * @deck_1: the first deck
 * @deck_2: the second deck
 *
 * Return: positive if greater, negative if lesser else 0
 */
int cmp_deck_func(const void *deck_1, const void *deck_2)
{
	deck_node_t *d_1 = *(deck_node_t **)deck_1;
	deck_node_t *d_2 = *(deck_node_t **)deck_2;

	if (d_1->card->kind != d_2->card->kind)
		return (d_1->card->kind - d_2->card->kind);
	else
		return (get_card_value(d_1->card->value) - get_card_value(d_2->card->value));
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: the deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *temp = *deck;
	deck_node_t *cards[52];
	size_t i;

	for (i = 0; i < 52; i++)
	{
		cards[i] = temp;
		temp = temp->next;
	}

	qsort(cards, 52, sizeof(deck_node_t *), cmp_deck_func);

	*deck = cards[0];
	cards[0]->prev = NULL;
	for (i = 1; i < 52; i++)
	{
		cards[i - 1]->next = cards[i];
		cards[i]->prev = cards[i - 1];
	}
	cards[51]->next = NULL;
}
