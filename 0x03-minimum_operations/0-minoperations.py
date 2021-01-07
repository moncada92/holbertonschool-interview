#!/usr/bin/env python3
"""
Minimum Operations
"""

def minOperations(n):
  """
  caluclate result the minimum operations
  """
  count = 0
  copy = 1
  tmp = 0

  while copy < n:
    if n % copy == 0:
      tmp = copy
      copy *= 2
      count += 1
    else:
      copy = tmp
    count += 1

  return count
