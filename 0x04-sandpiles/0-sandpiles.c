#include "sandpiles.h"

/**
 * print_grid - prints "=" + a newline + a grid
 * @grid: the grid the print
 * Return: void
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_grid - copied a grid into another
 * @grid1: the grid to copy
 * @gridc: the copy of the first grid
 * Return: void
 */
void copy_grid(int grid1[3][3], int gridc[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			gridc[i][j] = grid1[i][j];
		}
	}
}

/**
 * topple_and_check - topples a grid only once and check if it's stable
 * @grid1 : the grid
 * Return: 1 if stable, 0 if not yet
 */
int topple_and_check(int grid1[3][3])
{
	int i, j;
	int gridc[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	copy_grid(grid1, gridc);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (gridc[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid1[i - 1][j] += 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] += 1;
				if (i + 1 < 3)
					grid1[i + 1][j] += 1;
				if (j + 1 < 3)
					grid1[i][j + 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				print_grid(grid1);
				return (0);
			}
		}
	}
	return (1);
}

/**
 * sandpiles_sum - a function that computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 * Return: none
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				stable = 0;
		}
	}
	if (stable == 1)
		return;
	print_grid(grid1);
	while (stable == 0)
	{
		stable = topple_and_check(grid1);
	}
}
