#include "sort.h"

/**
 * selection_sort - function that sort array of integers
 * @array: array to be sorted
 * @size: size of n
 *
 * Return: Sorted integers in ascending order
 */

void selection_sort(int *array, size_t size)
{
	int i, n = (int)size;
	int j, minj_val, tmp;

	if (!array)
		return;

	for (i = 0; i < n - 1; i++)
	{
		minj_val = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[minj_val])
			{
				minj_val = j;
			}
		}
		if (minj_val != i)
		{
			tmp = array[i];
			array[i] = array[minj_val];
			array[minj_val] = tmp;
			print_array(array, size);
		}
	}
}
