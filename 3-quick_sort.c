#include "sort.h"

int lomuto_part(int *array, int low, int high, size_t size);
void sort(int *array, int low, int high, size_t size);
void swap(int *array, int a, int b, size_t size);

/**
 * quick_sort -  sorts an array of integers in using the Quick sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array)
		sort(array, 0, size - 1, size);
}

/**
 * lomuto_part - partitions array into parts
 * @array: the array to be partitioned
 * @low: first index of the array
 * @high: last index of the array
 * @size: size of array
 */
int lomuto_part(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}

	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
 * sort - sorts an array of integer using quick sort method
 * @array: the array to be sorted
 * @low: beginning of the array
 * @high: end of the array
 * @size: size of array
 */
void sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_part(array, low, high, size);
		sort(array, low, pi - 1, size);
		sort(array, pi + 1, high, size);
	}
}

/**
 * swap - swaps two integers
 * @array: array that contains integer to be swapped
 * @a: index of the first integer
 * @b: index of the second integer
 * @size: size of array
 */
void swap(int *array, int a, int b, size_t size)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	if (array[a] != array[b])
		print_array(array, size);
}
