#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))
boxes = [{}]
print(canUnlockAll(boxes), "\t: False")
print('-----------------------------')
boxes = [[2]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')
boxes =  [[1, 5], [2, 0, 3], [3, 88, 1], [4, 2], [6]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')
boxes = [[1, 2], ['hey', 'you'], ['sup']]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')
