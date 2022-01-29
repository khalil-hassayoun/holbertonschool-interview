#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc : number of arguments
 * @argv: array of pointers to arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i, l1, l2;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	l1 = check_argument(argv[1]);
	l2 = check_argument(argv[2]);
	result = prepare_result(l1 + l2);
	multiplication(argv[1], argv[2], l1, l2, result);
	for (i = 0; result[i] == '0' && result[i + 1]; i++)
	{
		;
	}
	printf("%s\n", &result[i]);
	free(result);
	return (0);
}

/**
 * check_argument - checks if argument is a valid integer
 * @argv: the argument
 * Return: returns the length of argument
 */
int check_argument(char *argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (i);
}

/**
 * prepare_result - allocates a memory for the result
 * @length: length of the result
 * Return: A pointer to the empty allocated memory
 */
char *prepare_result(int length)
{
	char *p;
	int i;

	p = malloc(sizeof(char) * (length + 1));
	if (!p)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 0; i < length; i++)
	{
		p[i] = '0';
	}
	p[i] = '\0';
	return (p);
}

/**
 * multiplication - multiplies 2 arrays of characters as if they were 2 numbers
 * @argv1: array of first number
 * @argv2: array of second number
 * @l1: length of first array
 * @l2: length of second array
 * @result: array of the result of multiplication
 */
void multiplication(char *argv1, char *argv2, int l1, int l2, char *result)
{
	int i, j;

	for (i = l2 - 1; i >= 0; i--)
	{
		for (j = l1 - 1; j >= 0; j--)
		{
			insert(result, (argv2[i] - '0') * (argv1[j] - '0'), i + j + 1);
		}
	}
}
/**
 * insert - inserts the product of 2 numbers in an array of characters
 * @result: the array of result
 * @x: the product of 2 numbers
 * @position: position of insertion in the array
 */
void insert(char *result, int x, int position)
{
	x = x + (result[position] - '0');
	while (x > 0)
	{
		result[position] = (x % 10) + '0';
		x /= 10;
		if (x == 0)
			break;
		position--;
		x += (result[position] - '0');
	}
}
