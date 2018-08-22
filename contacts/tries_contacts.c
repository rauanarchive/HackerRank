#!/bin/python3

import math
import os
import random
import re
import sys
from typing import Tuple


class TrieNode(object):
    def __init__(self, char: str):
        self.char = char
        self.children = []
        self.word_finished = False
        self.counter = 1

def add(root, word: str):
    node = root
    for char in word:
        found_in_child = False
        for child in node.children:
            if child.char == char:
                child.counter += 1
                node = child
                found_in_child = True
                break
        if not found_in_child:
            new_node = TrieNode(char)
            node.children.append(new_node)
            node = new_node
        node.word_finished = True

def find_prefix(root, prefix: str) -> Tuple[bool, int]:
    node = root
    if not root.children:
        return False, 0
    for char in prefix:
        char_not_found = True
        for child in node.children:
            if child.char == char:
                char_not_found = False
                node = child
                break
        if char_not_found:
            return False, 0
    return True, node.counter





if __name__ == '__main__':
    n = int(input())
    root = TrieNode('*')

    for n_itr in range(n):
        opContact = input().split()

        op = opContact[0]
        contact = opContact[1]
        if op == 'add':
            add(root,contact)
        if op == 'find':
            answer, count = find_prefix(root,contact)
            if answer: print(count)
            else: print(0)
