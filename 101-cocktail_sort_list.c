#include "sort.h"
#include <stdio.h>

/**
 *  * swap_nodes - Swaps two nodes in a doubly linked list
 *   * @list: Pointer to the head of the doubly linked list
 *    * @a: First node to swap
 *     * @b: Second node to swap
 *      */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b);

/**
 *  * cocktail_sort_list - Sorts a doubly linked list of integers
 *   * in ascending order using Cocktail Shaker sort
 *    * @list: Pointer to the head of the doubly linked list
 *     */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	do
	{
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &current->next);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;
		while (current != NULL && current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &current->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

	} while (swapped);
}

void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *temp;

	if (*a == NULL || *b == NULL)
		return;

	temp = (*a)->prev;
	if (temp != NULL)
		temp->next = *b;
	else
		*list = *b;

	(*b)->prev = temp;
	(*a)->prev = *b;
	(*a)->next = (*b)->next;

	if ((*b)->next != NULL)
		(*b)->next->prev = *a;

	(*b)->next = *a;
}

