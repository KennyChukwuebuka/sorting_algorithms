#include "sort.h"

/**
 * lomuto_partition_scheme - Function for quick sort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: index of pivot final sorted partition
 */
int lomuto_partition_scheme(int *array, int low, int high, size_t size)
{
	int a, b, pivot, tmp;

	pivot = array[high];
	a = low;
	for (a = b = low; b < high; b++)
	{
		if (array[b] < pivot)
		{
			tmp = array[a];
			array[a] = array[b];
			array[b] = tmp;
			if (array[a] != array[b])
				print_array(array, size);
			a++;
		}
	}
	tmp = array[a];
	array[a] = array[high];
	array[high] = tmp;
	if (array[a] != array[high])
		print_array(array, size);
	return (a);
}

/**
 * quick_sort_recursive - function for Quick sort.
 * @array: Array to be sorted.
 * @low: Starting index for the partition.
 * @high: Ending index for the partition.
 * @size: Size of array
 * Return: Nothing
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int j;

	if (low < high)
	{
		j = lomuto_partition_scheme(array, low, high, size);
		quick_sort_recursive(array, low, j - 1, size);
		quick_sort_recursive(array, j + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts array of integers
 * @array: array of integers
 * @size: size of the array
 * Return: sorted element
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);

}

