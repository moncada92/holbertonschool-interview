#!/usr/bin/python3
""" module rain """


def rain(walls):
    """ raun function """
    cut_wall = walls[1:-2]
    count = 0
    for i in cut_wall:
        count = count + i
    return count
