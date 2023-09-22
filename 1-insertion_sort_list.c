#include "sort.h"

/**
 * swap - Swap two nodes.
 * @head: head of the doubly-linked list.
 * @node1: first node to swap.
 * @node2: second node to swap.
 */

void swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *
 * @list: A pointer to the head of a doubly-linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *inserted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		inserted = iterator->prev;
		while (inserted != NULL && iterator->n < inserted->n)
		{
			swap(list, &inserted, iterator);
			print_list((const listint_t *)*list);
		}
	}
}
