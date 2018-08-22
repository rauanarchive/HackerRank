#!/bin/python3

import math
import os
import random
import re
import sys

# A program to count the number of ways to reach n'th stair

def stepPerms(n):
    if (n==1): return 1
    if (n==2): return 2
    if (n==3): return 4
    res = [0 for x in range(1,5)] # Creates list res witth all elements 0
    res[1] = 1
    res[2] = 2
    res[3] = 4

    for i in range(4,n+1):
        j=1
        c=0
        while (j<=3):
            print("i-j={}".format(i-j))
            c = c + res[i-j]
            j = j+1
        res.append(c)

    return res[n]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = int(input())

    for s_itr in range(s):
        n = int(input())

        res = stepPerms(n)

        fptr.write(str(res) + '\n')

    fptr.close()
