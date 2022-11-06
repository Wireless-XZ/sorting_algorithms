#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				array[i] = array[i] ^ array[i + 1];
				array[i + 1] = array[i + 1] ^ array[i];
				array[i] = array[i] ^ array[i + 1];
				print_array(array, size);
			}
		}
	}
}
