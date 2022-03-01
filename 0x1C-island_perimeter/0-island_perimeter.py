#!/usr/bin/python3
"""
This module contains the function island_perimeter
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid
    """
    perimeter = 0
    for c in range(len(grid)):
        for i in range(len(grid[c])):
            if grid[c][i] == 1:
                if c - 1 < 0 or grid[c - 1][i] == 0:
                    perimeter += 1
                if i - 1 < 0 or grid[c][i - 1] == 0:
                    perimeter += 1
                if i + 1 >= len(grid[c]) or grid[c][i + 1] == 0:
                    perimeter += 1
                if c + 1 >= len(grid) or grid[c + 1][i] == 0:
                    perimeter += 1
    return perimeter
