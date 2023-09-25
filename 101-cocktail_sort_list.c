#include "sort.h"

void swap_node_head(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_tail(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_head - swap a node in a listint_t doubly_linked_list
 * of integer with the node in front of it
 * @list: a pointer to the head of the linked list
 * @tail: a pointer to the tail of the linked list
 * @shaker: a pointer of the current swapping node
 */
void swap_node_head(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_node_tail - swap a node in a listint_t doubly_linked list
 * of integers with the node behind it.
 * @list: A pointer to the head of a doubly_linked list of integers
 * @tail: A pointer to the tail of the doubly_linked list
 * @shaker: a pointer to the current swapping node of the cocktail shaker algo
 */
void swap_node_tail(listint_t **list, listint **tail, listint_t **shaker)
{
	listint *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly_linked_list of integers in
 * ascending order using the cocktail shaker algorith
 * @list: a pointer to the head of the listint_t doubly_linked list
 * 
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_head(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_tail(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
