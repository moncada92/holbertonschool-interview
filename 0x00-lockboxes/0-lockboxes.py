#!/usr/bin/python3


def canUnlockAll(boxes):
    """Lockboxes Holberton Interview"""
    visit = set()
    stack = [0]

    if boxes is None or boxes == []:
        return False
    while stack:
        box = stack.pop()
        visit.add(box)

        for key in boxes[box]:
            if key not in visit:
                stack.append(key)

    return len(visit) == len(boxes)
