#!/usr/bin/python3

"""makeChange function."""


def makeChange(coins, total):
    """Returns the fewest number of coins needed to meet a given total"""
    if total <= 0:
        return 0
    res = [total + 1] * (total + 1)
    res[0] = 0
    for a in range(1, total + 1):
        for b in range(0, len(coins)):
            if coins[b] <= a:
                res[a] = min(res[a], res[a - coins[b]] + 1)
    return -1 if res[total] > total else res[total]
