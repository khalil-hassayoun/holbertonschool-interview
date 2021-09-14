#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: head of the singly linked list
 * Return: 1 if there is a cycle, otherwise 0
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise, *hare;

	if (!list)
		return (0);
	tortoise = list;
	if (!list->next)
		return (0);
	hare = (list->next)->next;
	while (hare && hare->next)
	{
		if (tortoise == hare)
			return (1);
		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}
	return (0);
}
