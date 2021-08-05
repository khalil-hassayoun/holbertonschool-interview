#include "binary_trees.h"

/**
 * find_parent - finds the first node that doesn't have a child,
 * following the Heap order
 * @root: pointer to the root node
 * Return: returns the found node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *array[1024];
	int i, insert;

	for (i = 0; i < 1024; i++)
		array[i] = NULL;
	i = 0;
	array[i] = root;
	insert = 1;
	while (array[i] && i < 1024)
	{
		if (array[i]->left)
		{
			array[insert] = array[i]->left;
			insert++;
		}
		else
		{
			return (array[i]);
		}
		if (array[i]->right)
		{
			array[insert] = array[i]->right;
			insert++;
		}
		else
		{
			return (array[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * swap - swaps 2 whole nodes
 * @root: double pointer to the root node
 * @node1: parent node
 * @node2: child node
 */
void swap(heap_t **root, heap_t *node1, heap_t *node2)
{
	heap_t *left, *right;

	if (!root || !*root)
		return;
	if (!node1 || !node2)
		return;
	if (node2->left)
		(node2->left)->parent = node1;
	if (node2->right)
		node2->right->parent = node1;
	if (node1->left && node1->left != node2)
		(node1->left)->parent = node2;
	if (node1->right && node1->right != node2)
		(node1->right)->parent = node2;
	if (node1 == *root)
		*root = node2;
	node2->parent = node1->parent;
	if ((node1->parent) && (node1 == node1->parent->left))
		node1->parent->left = node2;
	if ((node1->parent) && (node1 == node1->parent->right))
		node1->parent->right = node2;
	if (node2 == node1->left)
	{
		node1->left = node2->left;
		node2->left = node1;
		right = node1->right;
		node1->right = node2->right;
		node2->right = right;
	}
	if (node2 == node1->right)
	{
		node1->right = node2->right;
		node2->right = node1;
		left = node1->left;
		node1->left = node2->left;
		node2->left = left;
	}
	node1->parent = node2;
}

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: the value store in the node to be inserted
 * Return: the address of the newly inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (!root)
		return (NULL);
	else if (!*root)
	{
		*root = (heap_t *)binary_tree_node(NULL, value);
		return (*root);
	}
	parent = find_parent(*root);
	new = (heap_t *)binary_tree_node(parent, value);
	if (!new)
		return (NULL);
	if (!parent->left)
		parent->left = new;
	else if (!parent->right)
		parent->right = new;
	while (new->parent && new->n > (new->parent)->n)
	{
		swap(root, new->parent, new);
	}
	return (new);
}
