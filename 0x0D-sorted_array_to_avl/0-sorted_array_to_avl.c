#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 *
 * @array: The array to be converted
 * @size: Size of the array
 * Return: a pointer to root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int i;

	if (!array || size < 1)
		return (NULL);
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] < array[i - 1])
			return (NULL);
	}
	return (createAVL(array, 0, (int)size - 1, NULL));
}

/**
 * createAVL - Builds an AVL tree from an array
 *
 * @array: The array to be converted
 * @start: start index of the subarray
 * @end: last index of the subarray
 * @parent: parent of the currently created node
 * Return: a pointer to root node of the created AVL tree
 */
avl_t *createAVL(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	root->n = array[mid];
	root->parent = parent;
	root->left = createAVL(array, start, mid - 1, root);
	root->right = createAVL(array, mid + 1, end, root);
	return (root);
}
