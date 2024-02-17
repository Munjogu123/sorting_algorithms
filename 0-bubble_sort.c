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
 * bubble_sort - implements bubble sort algortithm
 * @array: array to sort
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool value;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		value = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				value = true;
			}
		}
		if (value == false)
			break;
	}
}
