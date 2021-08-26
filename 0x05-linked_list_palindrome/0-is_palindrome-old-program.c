#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - a function that checks if
 * a singly linked list is a palindrome
 * @head: address of the head of the list
 * Return: 1 if palindrome and 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *tmp;
	int *array, i, size = 0;

	if ((!head || !(*head)) || !(*head)->next)
		return (1);
	tmp = *head;
	while (tmp)
	{
		array = realloc(array, sizeof(int) * size + 1);
		array[size] = tmp->n;
		size++;
		tmp = tmp->next;
	}
	for (i = 0; i < (size / 2); i++)
	{
		if (array[i] != array[size - 1 - i])
		{
			free(array);
			return (0);
		}
	}
	free(array);
	return (1);
}
