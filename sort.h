#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*--------------------- all mandatory task prototypes ---------------*/

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *swap_ele_node(listint_t *node, listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition_scheme(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/*------------------all advance task prototypes-------------------------*/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap_sort(int *a_swp, int *b_swp);
void Heap_Convert(int *array, size_t size, int start, size_t end);
#endif /*sort.h*/
