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
 * partition - divides the array into subarrays until sorted
 * @array: array to be sorted
 * @start: starting index
 * @end: lower bound
 * @size: size of the array
 *
 * Return: index for the pivot element
*/
int partition(int *array, int start, int end, size_t size)
{
	int i, j, pivot;

	pivot = array[end];
	i = start;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[end]);
	print_array(array, size);

	return (i);
}

/**
 * quicksort_recursion - executes the algorithm
 * @array: array to be sorted
 * @start: starting index
 * @end: lower bound
 * @size: size of the array
*/
void quicksort_recursion(int *array, int start, int end, size_t size)
{
	if (start < end)
	{
		size_t index = partition(array, start, end, size);

		quicksort_recursion(array, start, index - 1, size);
		quicksort_recursion(array, index + 1, end, size);
	}
}

/**
 * quick_sort - implements quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	size_t end = size - 1;

	quicksort_recursion(array, 0, end, size);
}
