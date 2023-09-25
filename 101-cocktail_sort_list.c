#include "sort.h"

/**
 * swap - swaps adjacent elements from left to right
 * @list: doubly linked list
 * @node1: node to swap
 * @node2: node to swap
 */
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts doubly linked list of ints in ascending order
 * @list: the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *swap_node;
	bool swapped = true;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = false;
		for (curr = *list; curr->next->next != NULL; curr = curr->next)
		{
			swap_node = curr->next;
			if (curr->n > swap_node->n)
			{
				swap(list, curr, swap_node);
				curr = swap_node;
				swapped = true;
				print_list((const listint_t *)*list);
			}
		}
		if (!swapped)
			break;
		swapped = false;
		for (curr = curr->next; curr->prev->prev != NULL; curr = curr->prev)
		{
			swap_node = curr->prev;
			if (curr->n < swap_node->n)
			{
				swap(list, swap_node, curr);
				curr = swap_node;
				swapped = true;
				print_list((const listint_t *)*list);
			}
		}
	}
}
