#include "sort.h"
/**
 * swap - swaps two positions
 * @array1: array1
 * @array2: array2
 * Return: is a void
 */
void swap(int *array1, int *array2)
{
	int temp;

	temp = *array1;
	*array1 = *array2;
	*array2 = temp;
}
/**
 * heap - makes array into a heap
 * @array: ptr to int array
 * @size: size of array
 * @i: max point
 * @length: size of the array in heap_sort fn
 * Return: is a void
 */
void heap(int *array, int size, int i, int length)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[max] < array[left])
	{
		max = left;
	}

	if (right < size && array[max] < array[right])
	{
		max = right;
	}

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, length);
		heap(array, size, max, length);
	}
}

/**
 * heap_sort - sort and array (heap method)
 * @array: array to sort
 * @size: size of array
 * Return: is a void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!size || !array)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		heap(array, size, i, size);
	}
	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}
		heap(array, i, 0, size);
	}
}
