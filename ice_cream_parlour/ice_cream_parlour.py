#!/bin/python3

import math
import os
import random
import re
import sys

def mergeSort(alist):
    # print("Splitting ",alist)
    if len(alist)>1:
        # integer division
        mid = len(alist)//2
        # slicing from left to mid
        lefthalf = alist[:mid]
        # slicing from mid to right
        righthalf = alist[mid:]
        mergeSort(lefthalf)
        mergeSort(righthalf)

        i=0
        j=0
        k=0
        # this while loop works for one-element array
        # ideally we expect len(lefthalf) and len(righthalf)
        # to be one
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1
        # when going up the recursion tree, we merge bigger subarrays
        # in the two while loops
        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
    # print("Merging ",alist)

# Complete the whatFlavors function below.
def whatFlavors(cost, money):
    hash_table = {}
    deep_cost = [0]*len(cost)

    for k in range(0,len(cost)):
        deep_cost[k]=cost[k]
    for k in range(0,len(cost)):
        hash_table[deep_cost[k]]=k+1

    # for k in range(0,len(cost)):
    #     print("hash_table[{}]={}".format(deep_cost[k],k+1))
    mergeSort(cost)
    # print("after sorting")
    # for k in range(0,len(cost)):
    #     print("hash_table[{}]={}".format(deep_cost[k],k+1))

    lhs = 0
    rhs = len(cost)-1
    # print("printing cost list")
    # for k in range(0,len(cost)):
    #     print("cost[{}]={}".format(k,cost[k]))
    while lhs < rhs:
        sum = cost[lhs] + cost[rhs]
        if sum == money:
            print(hash_table[cost[lhs]],hash_table[cost[rhs]])
            return
        elif sum < money:
            lhs+=1
        else:
            rhs-=1




if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        money = int(input())

        n = int(input())

        cost = list(map(int, input().rstrip().split()))

        whatFlavors(cost, money)

# 2
# 4
# 5
# 1 4 5 3 2
# 4
# 4
# 2 2 4 3
