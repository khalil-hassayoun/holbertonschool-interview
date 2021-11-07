#include "search.h"

/**
 * cp -  a function that checks if a value is between prev and tmp
 * @prev: first node
 * @tmp: last node
 * @value: value to search for
 * Return: the node that contains the value or NULL
 */
skiplist_t *cp(skiplist_t *prev, skiplist_t *tmp, int value)
{
	while (prev != tmp->next)
	{
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: a pointer to the head of the skip list
 * @value: the value to search for
 * Return: a pointer to the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list, *prev = list;

	while (tmp)
	{
		if ((tmp->n < value || ((tmp->n == value) && !(cp(prev, tmp, value))))
		&& tmp->next)
		{
			if (tmp->index)
				printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
			prev = tmp;
			if (tmp->express)
			{
				tmp = tmp->express;
			}
			else
			{
				while (tmp->next)
					tmp = tmp->next;
			}
		}
		else
		{
			if (prev->n > value)
				return (NULL);
			if (tmp->n >= value)
				printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
					prev->index, tmp->index);
			while (prev && prev != tmp->next)
			{
				printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				prev = prev->next;
			}
			return (NULL);
		}
	}
	return (NULL);
}
