#include "binary_trees.h"
#include <limits.h>
/**
 * max - get the max value
 *
 * @a: val
 * @b: val
 * Return: int
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * height- get the height of root node
 *
 * @N: node
 * Return: int
 */
int height(const binary_tree_t *N)
{
	if (N == NULL)
		return (0);
	return (1 + max(height(N->left), height(N->right)));
}

/**
 * isBST - check if the tree is bst
 *
 * @tree: root
 * @min: min val
 * @max: max val
 * Return: 1 if true else 0
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (isBST(tree->left, min, tree->n - 1) &&
		isBST(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - check if th etree is avl
 *
 * @tree: node
 * Return: int
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	int left, right;

	if (tree == NULL)
		return (0);

	if (!isBST(tree, INT_MIN, INT_MAX))
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	if (abs(right - left) > 1)
		return (0);

	if (!(tree->left) || !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
