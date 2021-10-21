#!/usr/bin/python3
""" program that solves the N queens problem """
import sys


def isSafe(Board, line, i):
    """ checks if we can insert queen at column i in that line in Board"""
    for x in range(line):
        if (Board[x] == i or
                Board[x] + line - x == i or
                Board[x] + x - line == i):
            return False
    return True


def Fill_line(Board, line):
    """ fills each line of the board with the correct index """
    for i in range(len(Board)):
        if isSafe(Board, line, i):
            Board[line] = i
            if line < len(Board) - 1:
                Fill_line(Board, line + 1)
            else:
                print([[i, Board[i]] for i in range(len(Board))])

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)
try:
    n = int(sys.argv[1])
except:
    print("N must be a number")
    sys.exit(1)
if n < 4:
    print("N must be at least 4")
    sys.exit(1)

Board = [-1 for i in range(n)]
Fill_line(Board, 0)
