#include "sort.h"

/**
 * cocktail_sort_list - sorts doubly linked list of ints in ascending order
 * @list: the head of the list
 *
 * @Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *tail, *swap_node;
	bool swapped = true;

	if (!list || !(*list) || !(*list)->next)
		return;

	tail = *list;
	while (tail->next)
		tail = tail->next;

	while (swapped)
	{
		swapped = false;
		for (curr = *list; curr->next->next != NULL; curr = curr->next)
		{
			swap_node = curr->next;
			if (curr->n > swap_node->n)
			{
				curr->next = swap_node->next;
				if (swap_node->next)
					swap_node->next->prev = curr;
				swap_node->prev = curr->prev;
				swap_node->next = curr;
				if (curr->prev)
					curr->prev->next = swap_node;
				else
					*list = swap_node;
				curr->prev = swap_node;
				curr = swap_node;
				swapped = true;
				print_list((const listint_t *)*list);
			}
		}
		if (!swapped)
			break;
		swapped = false;
		for (curr = tail; curr->prev->prev != NULL; curr = curr->prev)
		{
			swap_node = curr->prev;
			if (curr->n < swap_node->n)
			{
				curr->prev = swap_node->prev;
				if (swap_node->prev)
					swap_node->prev->next = curr;
				else
					*list = curr;
				if (curr->next)
					curr->next->prev = swap_node;
				else
					tail = swap_node;
				swap_node->prev = curr;
				swap_node->next = curr->next;
				curr->next = swap_node;
				curr = swap_node;
				swapped = true;
				print_list((const listint_t *)*list);
			}
		}
		if (!swapped)
			break;
	}
}
