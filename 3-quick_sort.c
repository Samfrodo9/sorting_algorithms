#include "sort.h"

/**
 * quick_sort - A function that sorts an array using Quick Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quicksort_recursive(array, 0, size - 1, size);
}

/**
 * partition - Lomuto partition scheme for Quick Sort
 * @array: Pointer to the array
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: size of the array
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * quicksort_recursive - A recursive function to perform Quick Sort
 * @array: Pointer to the array
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: the size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);

		quicksort_recursive(array, low, partition_index - 1, size);
		quicksort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
