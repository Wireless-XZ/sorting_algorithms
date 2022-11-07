#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (array[j] < array[i])
			{
				array[i] = array[i] ^ array[j];
				array[j] = array[j] ^ array[i];
				array[i] = array[i] ^ array[j];
			}
		}
		print_array(array, size);
	}
}
