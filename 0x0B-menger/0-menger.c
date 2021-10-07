#include "menger.h"

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 */
void menger(int level)
{
	char *sponge;
	int l;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	sponge = malloc(sizeof(char) * 3);
	sponge[0] = '#';
	sponge[1] = '\n';
	sponge[2] = '\0';
	l = 0;
	while (l < level)
	{
		l++;
		sponge = level_up(sponge, l);
	}
	printf("%s", sponge);
	free(sponge);
}

/**
 * level_up - a function that increases the level of a sponge by one level
 * @sponge: a string that contains the initial Merge Sponge
 * @level: The target level
 * Return: a string that contains the scaled up Merge Sponge
 */
char *level_up(char *sponge, int level)
{
	double size;

	size = pow((double)3, (double)level);
	return (build_sponge(sponge, (int)size));
}

/**
 * build_sponge - a function that returns the target Merge Sponge,
 * The function builds the border and center rows of the Merge Sponge,
 * then concatenates them together into one string
 * @sponge: The initial Merge Sponge
 * @size: size of the target Sponge
 * Return: a string that contains the scaled up Merge Sponge
 */
char *build_sponge(char *sponge, int size)
{
	int len, c, times;
	char *border, *center, *p_copy, *line;

	len = (size + 1) * (size / 3) + 1;
	border = malloc(sizeof(char) * len);
	center = malloc(sizeof(char) * len);
	p_copy = strdup((const char *)sponge);
	line = strtok(p_copy, "\n");
	c = 0;
	for (times = 0; times < 3; times++)
	{
		c = build_border_center(border, center, c, line, times);
	}
	center[c] = '\n';
	border[c] = '\n';
	c++;
	line = strtok(NULL, "\n");
	while (line)
	{
		for (times = 0; times < 3; times++)
		{
			c = build_border_center(border, center, c, line, times);
		}
		center[c] = '\n';
		border[c] = '\n';
		c++;
		line = strtok(NULL, "\n");
	}
	center[c] = '\0';
	border[c] = '\0';
	free(p_copy);
	free(sponge);
	sponge = concatenate(border, center, size);
	free(border);
	free(center);
	return (sponge);
}

/**
 * build_border_center - The function builds the border and center rows
 * @border: a string that contains the border row
 * @center: a string that contains the center row
 * @c: index of next character to be filled in border and center strings
 * @line: one line of the old Menger Sponge
 * @t: number of iteration
 * Return: index of next character to be filled in border and center strings
 */
int build_border_center(char *border, char *center, int c, char *line, int t)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (t != 1)
		{
		center[c] = line[i];
		}
		else
		{
			center[c] = ' ';
		}
		border[c] = line[i];
		i++;
		c++;
	}
	return (c);
}

/**
 * concatenate - a function that concatenates:
 * the border rows and the center row of the Menger Sponge in a new string.
 * Order of insertion : (border - center - border)
 * @border: a string that contains the border row
 * @center: a string that contains the center row
 * @size: size of the Target Menger Sponge
 * Return: a string that contains the scaled up Merge Sponge
 */
char *concatenate(char *border, char *center, int size)
{
	char *sponge;
	int len, i, c;

	len = ((size + 1) * size) + 1;
	sponge = malloc(sizeof(char) * len);
	c = 0;
	for (i = 0; border[i]; i++)
	{
		sponge[c] = border[i];
		c++;
	}
	for (i = 0; center[i]; i++)
	{
		sponge[c] = center[i];
		c++;
	}
	for (i = 0; border[i]; i++)
	{
		sponge[c] = border[i];
		c++;
	}
	sponge[c] = '\0';
	return (sponge);
}
