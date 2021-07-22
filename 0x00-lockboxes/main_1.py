#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

print(' ***** EXAMPLE 1 ******')
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 2 ******')
boxes = [[1, 4, 6], [2, 0], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 3 ******')
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes),  "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 4 ******')
boxes = [[1, 3], [3, 0, 1], [2], [0]]
print(canUnlockAll(boxes),  "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 5 ******')
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6], [7]]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 6 ******')
boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6], [7]]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 7 ******')
boxes = [[2], [3, 4], [1, 5]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 8 ******')
boxes = [[2]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 9 ******')
boxes = []
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 10 ******')
boxes = [[1, 2, 3], [], [], [], []]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 11 ******')
boxes = None
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 12 ******')
boxes = 'hello, is it me you looking for?'
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 13 ******')
boxes = [[0, 4, 4], [5], [3], [1], [2], [5]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 14 ******')
boxes = [[1, 4], [2], [0, 4, 1], [6], [3], [4, 1], [5, 6], [7]]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 15 ******')
boxes = [[1], [1], [1]]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 16 ******')
boxes = [[], [2], [4]]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 17 ******')
boxes = [[0, 1], [2, 3], {}, None]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 18 ******')
boxes = [[]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 20 ******')
boxes = [[1, 2], ['hey', 'you'], ['sup']]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 21 ******')
boxes = [{}, [2, 3], {}, None]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 22 ******')
boxes = [[0, 1], [2, 3], [7, 4], [2]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 23 ******')
boxes = [{}]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 24 ******')
boxes = [[2]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 25 ******')
boxes = [[], [1, 2, 7], [0, 3]]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 26 ******')
boxes = [[8], [3], [1]]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')

print(' ***** EXAMPLE 27 ******')
boxes = [[1, 5], [2, 0, 3], [3, 88, 1], [4, 2], [6]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')

print(' ***** EXAMPLE 28 ******')
boxes = [['leee'], [], [], [], []]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')
