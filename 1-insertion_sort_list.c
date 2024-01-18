#include "sort.h"

/**
 * swap - swap the elwment
 * @a: address 1
 * @b: address 2
 * Return: void
 */

void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: list of int
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *m;

	if (list == NULL || *list == NULL || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		m = i;
		i = i->next;
		while (m && m->prev)
		{
			if (m->prev->n > m->n)
			{
				swap(m->prev, m);
				if (!m->prev)
					*list = m;
				print_list((const listint_t *)*list);
			}
			else
				m = m->prev;
		}
	}
}

