#include "sort.h"

/**
* bubble_sort - sorts an array using the bubble sort algorithm
* @array: pointer to array to be sorted
* @size: size of array
* Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap;
	int temp;

	for (i = 0; i < (size - 1); i++)
	{
		swap = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j+1])
			{
				temp = array[j]; /*larger integer*/
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}

		if (!swap)
			break;
	}
}
