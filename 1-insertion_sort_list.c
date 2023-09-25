#include "sort.h"

/**
 * swap_nd - Swaps two nodes in a listint_t doubly_linked list
 * @head: a pointer to the head
 * @x1: the first node for swapping
 * @x2: the second node for swapping
 */

void swap_nd(listint_t **head, listint_t **x1, listint_t *x2)
{
	(*x1)->next = x2->next;
	if (x2->next != NULL)
		x2->next->prev = *x1;
	x2->prev = (*x1)->prev;
	x2->next = *x1;
	if ((*x1)->prev != NULL)
		(*x1)->prev->next = x2;
	else
		*head = x2;
	(*x1)->prev = x2;
	*x1 = x2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order
 * @list: A pointer to the head of the doubly linked list
 * Requirement: print the list after each time you swap the element
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *link, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (link = (*list)->next; link != NULL; link = temp)
	{
		temp = link->next;
		insert = link->prev;
		while (insert != NULL && link->n < insert->n)
		{
			swap_nd(list, &insert, link);
			print_list((const listint_t *)*list);
		}
	}
}
