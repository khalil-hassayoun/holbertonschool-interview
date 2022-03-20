#!/usr/bin/python3
"""  modules  """


def pascal_triangle(n):
    """ print pascal triangle """

    lst = [1]
    res = list()

    for i in range(n):
        res.append(lst)
        mylist = []
        mylist.append(lst[0])
        for j in range(len(lst)-1):
            mylist.append(lst[j]+lst[j+1])
        mylist.append(1)
        lst = mylist

    return res
