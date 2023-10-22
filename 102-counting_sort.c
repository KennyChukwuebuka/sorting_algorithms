#include "sort.h"

/**
 * counting_sort - Function that sort an array of integers in 
 * ascending order using counting sort.
 * @array: Array to sort.
 * @size: Size of the array.
 * Return: Sorted arrays in ascending order.
 */
void counting_sort(int *array, size_t size)
{
	int i, j_total, k_max, *sort_count, *output;

	if (!array || size < 2)
		return;

	k_max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k_max)
			k_max = array[i];
	}

	sort_count = calloc((k_max + 1), sizeof(int));
	if (!sort_count)
		return;
	for (i = 0; i < (int)size; i++)
		sort_count[array[i]]++;
	for (i = 0, j_total = 0; i < k_max + 1; i++)
	{
		j_total = sort_count[i] + j_total;
		sort_count[i] = j_total;
	}
	print_array(sort_count, k_max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < (int)size; i++)
	{
		output[sort_count[array[i]] - 1] = array[i];
		sort_count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(sort_count);
	free(output);

}
