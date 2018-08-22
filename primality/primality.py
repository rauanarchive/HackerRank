#!/bin/python3

import math
import os
import random
import re
import sys
def eratosphen_sieve(n):
    a = [True] * limit                          # Initialize the primality list
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in xrange(i*i, limit, i):     # Mark factors non-prime
                a[n] = False

def isPrime(n):
    print("n={}".format(n))
    eratosphen =list(range(2,n+3))
    print("len={}".format(len(eratosphen)))
    for i in range(2,n,1):
        print("eratosphen[{}]={}".format(i,eratosphen[i]))
    p = 1
    i = 1
    for i in range(2,n+1):
        if eratosphen[i]>p:
            p = eratosphen[i]
            while (i*p)<n:
    # marking multiplies of p
                eratosphen[i*p]=0
                i=i+1
    for i in range(2,n+1):
        if eratosphen[i]!= 0:
            print("{}".format(eratosphen[i]))





if __name__ == '__main__':
    p = int(input())

    for p_itr in range(p):
        n = int(input())
        isPrime(n)
