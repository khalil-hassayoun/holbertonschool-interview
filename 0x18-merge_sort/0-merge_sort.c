#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm and
 * implementing the top-down merge sort algorithm
 * @array: the array of integers
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int i;
	int *arr;

	if (!array || size < 2)
		return;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return;
	for (i = 0; i < (int)size; i++)
		arr[i] = array[i];

	split_merge(array, arr, 0, (int)(size - 1));
	free(arr);
}

/**
 * split_merge - splits the array into subarrays and
 * merge sort them using the top-down merge sort algorithm
 * @array: the array of integers
 * @arr: the copy of array
 * @first: index of first element
 * @last: index of last element
 */
void split_merge(int *array, int *arr, int first, int last)
{
	int n, mid;

	n = last - first + 1;
	if (n < 2)
		return;
	mid = (n / 2) + first;
	split_merge(array, arr, first, mid - 1);
	split_merge(array, arr, mid, last);
	merging(array, arr, first, mid, last);
}

/**
 * merging - merges 2 sorted subarrays in an unsorted array
 * @array: the unsorted array
 * @arr: the temporary array that contains subarrays
 * @first: index of first element in the first subarray
 * @mid: index of first element in the second subarray
 * @last: index of last element in second subarray
 */
void merging(int *array, int *arr, int first, int mid, int last)
{
	int i = first, j = mid, k = first;

	printf("Merging...\n");
	printf("[left]: ");
	print_array((const int *)&arr[first], mid - first);
	printf("[right]: ");
	print_array((const int *)&arr[mid], last - mid + 1);
	while (i < mid && j <= last)
	{
		if (arr[i] < arr[j])
		{
			array[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			array[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i < mid)
	{
		array[k] = arr[i];
		i++;
		k++;
	}
	while (j <= last)
	{
		array[k] = arr[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	for (i = first; i <= last; i++)
		arr[i] = array[i];
	print_array((const int *)&array[first], last - first + 1);
}
