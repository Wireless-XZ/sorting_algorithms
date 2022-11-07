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
	int y = 0, x = 0;

	for (i = 0; i < size; i++)
	{
		y = 0;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[i])
			{
				if (y == 0)
					y = j;
				else
				{
					if (array[j] < array[y])
						y = j;
				}
				x = 1;
			}
		}
		if (x)
		{
			array[i] = array[i] ^ array[y];
			array[y] = array[y] ^ array[i];
			array[i] = array[i] ^ array[y];
			print_array(array, size);
			x = 0;
		}
	}
}
