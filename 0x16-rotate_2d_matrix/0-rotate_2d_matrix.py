#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees clockwise """


def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix, rotate it 90 degrees clockwise """
    first = 0
    last = len(matrix) - 1
    while first < last:
        for i in range(first, last):
            aux = matrix[i][last]
            matrix[i][last] = matrix[first][i]
            aux2 = matrix[last][last + first - i]
            matrix[last][last + first - i] = aux
            aux = matrix[last + first - i][first]
            matrix[last + first - i][first] = aux2
            matrix[first][i] = aux
        first += 1
        last -= 1
