#!/usr/bin/python3
""" Module for Prime Game """


def isWinner(x, nums):
    """Prime Game"""
    if not nums or x < 1:
        return None
    n = max(nums)
    aux = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not aux[i]:
            continue
        for j in range(i*i, n + 1, i):
            aux[j] = False

    aux[0] = aux[1] = False
    c = 0
    for i in range(len(aux)):
        if aux[i]:
            c += 1
        aux[i] = c

    p1 = 0
    for n in nums:
        p1 += aux[n] % 2 == 1

    if p1 * 2 == len(nums):
        return None

    if p1 * 2 > len(nums):
        return "Maria"
    return "Ben"
