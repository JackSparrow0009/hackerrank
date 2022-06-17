#!/bin/python3

# Challenges: https://www.hackerrank.com/challenges/extra-long-factorials/problem

import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.
def extraLongFactorials(n):
    res = 1
    for i in range(n):
        res = res * (i + 1)
    print(res)

if __name__ == '__main__':
    n = int(input())

    extraLongFactorials(n)

