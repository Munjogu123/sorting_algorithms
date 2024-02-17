#include "sort.h"

/**
 * swap - swaps 2 elements
 * @a: element 1
 * @b: element 2
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - implements selection sort
 * @array: array to be sorted
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
