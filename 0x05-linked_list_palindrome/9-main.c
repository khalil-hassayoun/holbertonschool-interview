#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lists.h"

/**
 * main - check runtime of is_palindrome - not palindrome
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;
	clock_t start;
	clock_t end;
	clock_t diff;
	int i;

	head = NULL;
	for (i = 0; i < 1001; i++)
		add_nodeint_end(&head, i);
	for (i = 1000; i >= 0; i--)
		add_nodeint_end(&head, i);

	start = clock();

	for (i = 0; i < 10; i++)
		is_palindrome(&head);

	end = clock();

	diff = (double)(end - start) / 10;

	if (diff > 80)
		printf("Runtime too long\n");
	else
		printf("OK\n");

	free_listint(head);

	return (0);
}
