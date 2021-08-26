#include "lists.h"

/**
 * is_palindrome - a function that checks if
 * a singly linked list is a palindrome
 * @head: address of the head of the list
 * Return: 1 if palindrome and 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *tmp;
	int i, size = 0;
	listint_t *array[3000];

	if (!head)
		return (0);
	if (!(*head) || !(*head)->next)
		return (1);
	for (i = 0; i < 3000; i++)
		array[i] = NULL;
	tmp = *head;
	while (tmp)
	{
		array[size] = tmp;
		size++;
		tmp = tmp->next;
	}
	for (i = 0; i < (size / 2); i++)
	{
		if (array[i]->n != array[size - 1 - i]->n)
		{
			return (0);
		}
	}
	return (1);
}
