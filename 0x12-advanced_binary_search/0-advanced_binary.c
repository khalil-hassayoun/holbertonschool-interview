#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: the array
 * @size: size of the array
 * @value: the value to search for
 * Return: the index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);
	return (recursive_search(array, 0, (int)(size - 1), value));
}

/**
 * recursive_search - search recursively for value
 * @array: the array
 * @first: first index of the subarray
 * @last: last index of the subarray
 * @value: the value to search for
 * Return: the index where value is located or -1
 */
int recursive_search(int *array, int first, int last, int value)
{
	int mid, i;

	if (first > last)
		return (-1);
	mid = (first + last) / 2;
	if (array[mid] == value && first == last)
		return (mid);
	printf("Searching in array: ");
	for (i = first; i <= last; i++)
	{
		if (i != first)
		{
			printf(", ");
		}
		printf("%d", array[i]);
		if (i == last)
			printf("\n");
	}
	if (array[mid] >= value)
		return (recursive_search(array, first, mid, value));
	return (recursive_search(array, mid + 1, last, value));
}
