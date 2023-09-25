#include "sort.h"

/**
* counting_sort - sorts an array of integers in ascending order
* using the Counting sort algorithm
* @array: pointer to an array of integers
* @size: size of array
* Return: void
*/
void counting_sort(int *array, size_t size)
{
	size_t k;
	int *count, i, max, j;
	int *array_;

	if (array && size > 1)
	{
		max = array[0];
		for (k = 1; k < size; k++)
		{
			if (array[k] > max)
				max = array[k];
		}

		count = malloc(sizeof(int) * (max + 1));
		array_ = malloc(sizeof(int) * (size));
		if (count && array_)
		{
			for (i = 0; i <= max; i++)
			{
				count[i] = 0;
			}
			for (k = 0; k < size; k++)
			{
				++count[array[k]];
			}
			for (i = 1; i < max + 1; i++)
			{
				count[i] = count[i] + count[i - 1];
			}
			print_array(count, max + 1);
			for (j = size - 1; j >= 0; j--)
			{
				array_[--count[array[j]]] = array[j];
			}
			array = array_;

			/**
			*for (j = size - 1; j >= 0; j--)
			*	array[j] = array_[j];
			*free(count);
			*free(array);
			*/
		}
	}
}
