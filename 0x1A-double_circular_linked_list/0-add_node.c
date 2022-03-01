#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: address of the list starting node
 * @str: the data of the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node;

	if (!list || !str)
		return (NULL);
	node = malloc(sizeof(List));
	if (!node)
		return (NULL);
	node->str = strdup((const char *)str);
	if (!(node->str))
	{
		free(node);
		return (NULL);
	}
	if (!*list)
	{
		*list = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev = (*list)->prev;
		node->next = *list;
		node->prev->next = node;
		node->next->prev = node;
	}
	return (node);
}
/**
 * add_node_begin - Add a new node to the beginning of the circular linked list
 * @list: address of the list starting node
 * @str: the data of the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	if (!list || !str)
		return (NULL);
	node = malloc(sizeof(List));
	if (!node)
		return (NULL);
	node->str = strdup((const char *)str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	if (!*list)
	{
		*list = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev = (*list)->prev;
		node->next = *list;
		node->prev->next = node;
		node->next->prev = node;
		*list = node;
	}
	return (node);
}
