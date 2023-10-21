#include "sort.h"

/**
 * shell_sort - Sorts array of integers in
 * ascending order using shell sort technique.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Return: Sorted arrays
 */

void shell_sort(int *array, size_t size)
{
	int a, b, k, l, knuth, tmp;

	if (!array)
		return;

	l = (int)size;
	for (k = 1; k < l; k = (k * 3) + 1)
	{
		knuth = k;
	}

	for (k = knuth; k > 0; k = (k - 1) / 3)
	{
		for (a = k; a < l; a++)
		{
			tmp = array[a];

			for (b = a; b >= k && array[b - k] > tmp; b -= k)
			{
				array[b] = array[b - k];
			}
			array[b] = tmp;
		}
		print_array(array, size);
	}
}
