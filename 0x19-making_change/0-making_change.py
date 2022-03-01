#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed
to meet a given amount total.
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total
    """
    if total <= 0:
        return 0
    if not coins or min(coins) > total:
        return -1
    num_coins = 0
    coins.sort(reverse=True)
    i = 0
    while i < len(coins):
        if coins[i] <= total:
            num_coins += total // coins[i]
            total = total % coins[i]
        i += 1
    if total == 0:
        return num_coins
    else:
        return -1
