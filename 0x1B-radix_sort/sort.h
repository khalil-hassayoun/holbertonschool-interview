#ifndef SORT
#define SORT
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
/**
 * struct integer_s - singly linked list for integers storage
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list structure
 */
typedef struct integer_s
{
	int n;
	struct integer_s *next;
} integer_t;
void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void sorting_by_digits(int *array, size_t size, int power);
integer_t *add_node(integer_t **bucket, int n);
void free_list(integer_t *head);
#endif
