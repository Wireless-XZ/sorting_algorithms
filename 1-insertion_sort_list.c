#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: dooubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *dummy = *list, *current;

	if (!list || !(*list) || (!((*list)->next) && !((*list)->prev)))
		return;

	current = (*list)->next;
here:
	dummy = current->next;
	while (current->prev && (current->n < current->prev->n))
	{
		swap_nodes(&current);
		print_list(get_head(current));
	}
	if (dummy)
	{
		current = dummy;
		goto here;
	}
	*list = get_head(current);
}

/**
 * swap_nodes - swap two nodes of a doubly linked list
 * @dummy: one of the nodes to swap
 */
void swap_nodes(listint_t **dummy)
{
	listint_t *x, *y;

	if ((*dummy)->prev->prev == NULL)
		y = NULL;
	else
		y = (*dummy)->prev->prev;
	if ((*dummy)->next == NULL)
		x = NULL;
	else
		x = (*dummy)->next;
	(*dummy)->prev->prev = *dummy;
	(*dummy)->next = (*dummy)->prev;
	(*dummy)->prev->next = x;
	if (x)
		x->prev = (*dummy)->prev;
	(*dummy)->prev = y;
	if (y)
		y->next = *dummy;
}

/**
 * get_head - gets the head node of a doubly linked list
 * @dummy: current node of the linked list
 *
 * Return: the head node
 */
listint_t *get_head(listint_t *dummy)
{
	while (dummy)
	{
		if (dummy->prev == NULL)
			break;
		dummy = dummy->prev;
	}
	return (dummy);
}
