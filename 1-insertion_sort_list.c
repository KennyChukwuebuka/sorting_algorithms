#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * using the insertion sort algorithm
 * @list: list to sort
 * Return: sorted list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_ele_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap_ele_node - function that swap two element
 * @node: node to swap
 * @list: element list
 * Return: pointer to node
 */
listint_t *swap_ele_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev, *current_node = node;

	prev_node->next = current_node->next;
	if (current_node->next)
		current_node->next->prev = prev_node;
	current_node->next = prev_node;
	current_node->prev = prev_node->prev;
	prev_node->prev = current_node;
	if (current_node->prev)
		current_node->prev->next = current_node;
	else
		*list = current_node;
	return (current_node);
}


