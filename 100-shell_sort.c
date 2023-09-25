#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order
* using the Shell sort algorithm
* @array: pointer to an array of integers
* @size: size of the array
* Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t h, j, gap;
	int i;

	if (array && size > 1)
	{
		h = 0;
		while (h < (size + 1) / 3)
		{
			h = h * 3 + 1;
		}
		for (gap = h; gap >= 1; gap = (gap - 1) / 3)
		{
			for (j = gap; j < size; j++)
			{
				for (i = j - gap; i >= 0; i = i - gap)
				{
					if (array[i + gap] > array[i])
						break;
					swap(&array[i + gap], &array[i]);
				}
			}

			print_array(array, size);
		}
	}
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
