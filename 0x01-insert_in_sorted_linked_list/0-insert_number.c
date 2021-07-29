#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number in a singly linked list
 * @head: address of the head of the list
 * @number: the number to insert
 * Return: address of the new node or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmp, *prev;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	tmp = *head;
	prev = *head;
	while (tmp && tmp->n < number)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == *head)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	new->next = prev->next;
	prev->next = new;
	return (new);
}
