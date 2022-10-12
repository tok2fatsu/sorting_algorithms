#include "sort.h"

/**
 * swap_nodes - swaps to nodes of a a doubly linked list
 * @list: the list
 * @node_1: the first node
 * @node_2: the second node
 *
 * Return: 1 of swap happend otherwise 0
 */
int swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	listint_t *temp_1, *temp_2;

	if (node_1 == node_2 || node_1 == NULL || node_2 == NULL)
		return (0);

	temp_1 = node_1->prev;
	temp_2 = node_2->next;

	node_1->next = temp_2;
	node_1->prev = node_2;
	node_2->next = node_1;
	node_2->prev = temp_1;

	if (temp_1 != NULL)
		temp_1->next = node_2;
	if (temp_2 != NULL)
		temp_2->prev = node_1;

	if (node_1->prev == NULL)
		*list = node_1;
	if (node_2->prev == NULL)
		*list = node_2;

	print_list((const listint_t *)(*list));
	return (1);
}

/**
 * forward_bubble - performs a forwared buble sorting algorithm
 * @head: head of the list
 * @tail: will be set to be the tail of the list
 *
 * Return: umber of swaps performed
 */
int forward_bubble(listint_t **head, listint_t **tail)
{
	listint_t *node;
	int swaps = 0;

	if (head != NULL && *head != NULL)
	{
		node = *head;
		while (node != NULL)
		{
			*tail = node;
			if (node->next != NULL && node->n > node->next->n)
				swaps += swap_nodes(head, node, node->next);
			else
				node = node->next;
		}
	}
	return (swaps);
}

/**
 * backward_bubble - performs a backward bubble sort
 * @head: the head of the list
 * @tail: the tail of the list
 *
 * Return: number of swaps performed
 */

int backward_bubble(listint_t **head, listint_t *tail)
{
	listint_t *node;
	int swaps = 0;

	if (tail != NULL && tail != NULL)
	{
		node = tail;
		while (node != NULL)
		{
			if (node->prev != NULL && node->n < node->prev->n)
				swaps += swap_nodes(head, node->prev, node);
			else
				node = node->prev;
		}
	}
	return (swaps);
}

/**
 * cocktail_sort_list - bubble sort algorithm implementation
 * @list: the list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *tail;

	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		do {
			swap = forward_bubble(list, &tail);
			swap += backward_bubble(list, tail);
		} while (swap != 0);
	}
}
