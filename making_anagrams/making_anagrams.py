#!/bin/python3


from math import fabs
import os
import random
import re
import sys



if __name__ == '__main__':

    # reading input
    a = input()
    b = input()

    # initializing dictionaries
    occurences_a = {}
    occurences_b ={}
    for char in a :
        occurences_a[char]=0
    for char in b :
        occurences_b[char]=0


    # counting frequencies
    for char in a :
        occurences_a[char] = occurences_a[char]+1
    for char in b :
        occurences_b[char] = occurences_b[char]+1

    # finding the intersection of the keys/symbols
    intersection_keys = occurences_a.keys() & occurences_b.keys()
    must_delete_symbols = 0
    symmetric_difference = occurences_a.keys()^occurences_b.keys()

    # print(must_delete_symbols)
    # print(len(intersection_keys))
    for key in occurences_a.keys() & occurences_b.keys():
        must_delete_symbols+=fabs(int(occurences_a[key]))
    print(must_delete_symbols)

    #
    # print("intersection = {}".format(must_delete_symbols))
    #
    # for key_a in occurences_a.keys():
    #     print("occurences_a[{}]={}".format(key_a, occurences_a[key_a]))
    # for key_b in occurences_a.keys():
    #     print("occurences_b[{}]={}".format(key_b, occurences_b[key_b]))

#
# f : 1   j : 2
# c : 2   x : 1
# r : 1   w : 2
# x : 2   t : 1
# z : 1   r : 2
# w : 1   h : 2
# s : 1   v : 1
# a : 1   u : 1
# n : 1
# m : 2   l : 1
# l : 1   m : 3
# i : 1
# g : 1   p : 2
# y : 3   d : 1
# v : 1   o : 2
#         q : 1
#         b : 2
#         i : 1
#         s : 1
#
#
#
#
#         g : 1
#
#
#         e : 2
#
#         k : 1
