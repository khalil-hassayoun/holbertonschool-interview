#!/usr/bin/python3
"""
We have n number of locked boxes in front of us.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """a method that determines if all the boxes can be opened"""
    """ edge cases commented out """
    if boxes is None:
        return False
    if not isinstance(boxes, list):
        return False
    if boxes == []:
        return False
    if boxes == [[]]:
        return True
    if boxes[0] == [] and len(boxes) > 1:
        return False
    for i in boxes:
        if not isinstance(i, list):
            return False
        else:
            for item in i:
                if not isinstance(item, int):
                    return False
    Unlocked = [False for i in boxes]
    Unlocked[0] = True
    Open = [False for i in boxes]
    while [True for i in range(len(boxes))
           if Open[i] is False and Unlocked[i] is True]:
        for k in range(len(boxes)):
            if Unlocked[k] is True:
                Open[k] = True
                for i in boxes[k]:
                    try:
                        Unlocked[i] = True
                    except:
                        pass
    return False not in Unlocked
