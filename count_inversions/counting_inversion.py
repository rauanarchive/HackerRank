#!/bin/python3

import math
import os
import random
import re
import sys
def swap_pair(a,b):
    buf = a
    a   = b
    b   = buf
    return (a,b)

def swap(i,j,arr):
    buf = arr[i]
    k=j-1
    while k > i:
        arr[k], arr[k] = swap_pair(arr[k],arr[j])
        k = k-1
    return (arr[i],arr[j])
# Complete the countInversions function below.
def countInversions(arr):
    count = 0
    for i in range(0,len(arr)):
        for j in range(i+1,len(arr)):
            if arr[i]> arr[j]:
                arr[i], arr[j]=swap(i,j,arr)
                # b = arr[i]
                # arr[i]=arr[j]
                # arr[j]=b
                count=count+j-i
                print("i, j")
                print(i,j)
                print("i-j")
                print(j-i)
                print(arr)
    return count

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    # t = int(input())
    # t = 1
    # for t_itr in range(t):
    #     # n = int(input())
    #     n = 1
    #     arr = [2,1,3,1,2]
    #     # arr = list(map(int, input().rstrip().split()))
    #
    #     result = countInversions(arr)
    #     print(result)
    #     # fptr.write(str(result) + '\n')
    
    # fptr.close()
