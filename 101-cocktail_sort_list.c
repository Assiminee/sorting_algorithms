#include "sort.h"

/**
 * swap - swaps adjacent elements from left to right
 * @list: doubly linked list
 * @curr: node to swap
 * @swap_node: node to swap
 */
void swap(listint_t **list, listint_t **curr, listint_t *swap_node)
{
	(*curr)->next = swap_node->next;
	if (swap_node->next)
		swap_node->next->prev = (*curr);
	swap_node->prev = (*curr)->prev;
	swap_node->next = *curr;
	if ((*curr)->prev)
		(*curr)->prev->next = swap_node;
	else
		*list = swap_node;
	(*curr)->prev = swap_node;
}

/**
 * reverse_swap - swaps adjecent elements starting from the end of the list
 * @list: doubly linked list
 * @curr: node to swap
 * @swap_node: node to swap
 */
void reverse_swap(listint_t **list, listint_t **curr, listint_t *swap_node)
{
	(*curr)->prev = swap_node->prev;
	if (swap_node->prev)
		swap_node->prev->next = (*curr);
	else
		*list = *curr;
	if ((*curr)->next)
		(*curr)->next->prev = swap_node;
	swap_node->prev = *curr;
	swap_node->next = (*curr)->next;
	(*curr)->next = swap_node;
	*curr = swap_node;
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
				swap(list, &curr, swap_node);
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
				swap(list, &swap_node, curr);
				curr = swap_node;
				swapped = true;
				print_list((const listint_t *)*list);
			}
		}
	}
}
