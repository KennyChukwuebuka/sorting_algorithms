#include "sort.h"

/**
 * swap_sort - swap function
 * @a_swp: params a
 * @b_swp: param b
 **/
void swap_sort(int *a_swp, int *b_swp)
{
	int i = *a_swp;

	*a_swp = *b_swp;
	*b_swp = i;
}

/**
 * Heap_Convert - Function to covert
 * @array: array
 * @size: size of the array for print
 * @start: index
 * @end: size of the array to run
 */
void Heap_Convert(int *array, size_t size, int start, size_t end)
{
	int i_large = start;
	int i_left = 2 * start + 1;
	int i_right = 2 * start + 2;

	if (i_left < (int)end && array[i_left] > array[i_large])
		i_large = i_left;


	if (i_right < (int)end && array[i_right] > array[i_large])
		i_large = i_right;


	if (i_large != start)
	{
		swap_sort(&array[start], &array[i_large]);
		print_array(array, size);
		Heap_Convert(array, size, i_large, end);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		Heap_Convert(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap_sort(&array[0], &array[i]);
		print_array(array, size);
		Heap_Convert(array, size, 0, i);
	}
}
