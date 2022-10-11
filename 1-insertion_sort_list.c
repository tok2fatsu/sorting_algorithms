#include "sort.h"

/**
 * insertion_sort_list - sorts a list using insertion algorithm
 * @list: the doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp_a, *temp_b;

	if (list != NULL && *list != NULL)
	{
		node = (*list)->next;
		while (node != NULL)
		{
			temp_a = node;
			node = node->next;
			while (temp_a->prev != NULL && temp_a->prev->n > temp_a->n)
			{
				temp_b = temp_a->prev;
				temp_b->next = temp_a->next;
				temp_a->prev = temp_b->prev;

				if (temp_b->prev != NULL)
					temp_b->prev->next = temp_a;
				if (temp_a->next != NULL)
					temp_a->next->prev = temp_b;

				temp_a->next = temp_b;
				temp_b->prev = temp_a;

				if (temp_a->prev == NULL)
					*list = temp_a;

				print_list(*list);
			}
		}
	}
}
