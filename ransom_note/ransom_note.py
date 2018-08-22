#!/bin/python

import os
import random
import re
import sys
from collections import defaultdict

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    dict_note = defaultdict(list)
    dict_magazine = defaultdict(list)
    for word in magazine:
        dict_magazine[hash(word)].append(word)
    for word in note:
        dict_note[hash(word)].append(word)
    if (len(dict_note.keys()) > len(dict_magazine.keys())):
        print("No")
        return

    for key in dict_note.keys():
        if ( len(dict_note[key]) > len(dict_magazine[key])):
            print("No")
            return
    print("Yes")



if __name__ == '__main__':
    mn = raw_input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = raw_input().rstrip().split()

    note = raw_input().rstrip().split()

    checkMagazine(magazine, note)
