#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """
    caluclate result the minimum operations
    """
    quantity = n
    div = 2
    tmp = 0

    while (quantity > 1):
        if quantity % div == 0:
            quantity = int(quantity / div)
            tmp += div
            div = 2
        else:
            div += 1

    return tmp
