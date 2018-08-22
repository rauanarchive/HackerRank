#!/bin/python3

import math
import os
import random
import re
import sys


class Stack:
    def __init__(self):
        #declaring items
        self.items = []
    def isEmpty(self):
        return self.items == []
    def push(self, item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def peek(self):
        #return the top element
        return self.items[len(self.items)-1]
    def size(self):
        return len(self.items)

if __name__ == '__main__':


    t = int(input())
    comp_brack = { '}':'{', ']':'[', ')':'(' }

    for t_itr in range(t):
        expression = input()
        # print("expression={}".format(expression))
        brackets = Stack()
        balanced = True
        for char in expression:
            # checking if char is the closing bracket
            if char == '\n': print("newline detected")
            if char in comp_brack.keys():
                if not brackets.isEmpty():
                    c = brackets.pop()
                    if c is not comp_brack[char]:
                        balanced = False
                        break
                else : balanced = False
            else :
                brackets.push(char)
        # we either break it in 43 or exit it normally
        if (not brackets.isEmpty()):
            balanced = False
        if balanced : print("YES")
        else        : print ("NO")
