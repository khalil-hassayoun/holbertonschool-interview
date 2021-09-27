#include "slide_line.h"

/**
 * merge_left - a function that merges to the left 2 numbers:
 * the number on index i and its identical number on its right side
 * if they are contiguous or separated by zeros
 * @line: address of the array
 * @size: size of the array
 * @i: index of the first number to merge
 */
void merge_left(int *line, size_t size, int i)
{
	int c;

	c = i + 1;
	if (c == (int)size)
		return;
	while (c < (int)size && line[c] == 0)
		c++;
	if (c == (int)size || line[c] != line[i])
		return;
	line[i] *= 2;
	line[c] = 0;
}

/**
 * slide_left - slides the number on index i to the left
 * @line: the address of the array
 * @size: size of the array
 * @i: index of the number to slide
 */
void slide_left(int *line, size_t size, int i)
{
	int c;

	c = i + 1;
	while (c < (int)size && !line[c])
		c++;
	if (c < (int)size && line[c] != 0)
	{
		line[i] = line[c];
		line[c] = 0;
	}
}

/**
 * merge_right - a function that merges to the right 2 numbers:
 * the number on index i and its identical number on its left side
 * if they are contiguous or separated by zeros
 * @line: address of the array
 * @i: index of the first number to merge
 */
void merge_right(int *line, int i)
{
	int c;

	c = i - 1;
	if (c < 0)
		return;
	while (c >= 0 && line[c] == 0)
		c--;
	if (c >= 0 && line[c] == line[i])
	{
		line[i] *= 2;
		line[c] = 0;
	}
}

/**
 * slide_right - slides the number on index i to the right
 * @line: the address of the array
 * @i: index of the number to slide
 */
void slide_right(int *line, int i)
{
	int c;

	c = i - 1;
	while (c >= 0 && !line[c])
		c--;
	if (c >= 0 && line[c] != 0)
	{
		line[i] = line[c];
		line[c] = 0;
	}
}

/**
 * slide_line - a function that slides and merges an array of integers
 * @line: address of the array
 * @size: size of the array
 * @direction: slide to the left or to the right
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int i;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (!line)
		return (0);
	if (size < 2)
		return (1);
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < (int)size; i++)
		{
			if (line[i])
				merge_left(line, size, i);
		}
		for (i = 0; i < (int)size; i++)
		{
			if (line[i] == 0)
			{
				slide_left(line, size, i);
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = (int)(size - 1); i >= 0; i--)
		{
			if (line[i])
				merge_right(line, i);
		}
		for (i = (int)(size - 1); i >= 0; i--)
		{
			if (line[i] == 0)
			{
				slide_right(line, i);
			}
		}
	}
	return (1);
}
