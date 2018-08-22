from math import fabs

def number_needed(a, b):
    letterArray = [0] * 26
    for c in a:
        index = ord(c) - ord('a');
        letterArray[index]+=1
    for c in b:
        index = ord(c) - ord('a')
        letterArray[index]-=1
    for c in a :
        print("freq_a[{}]={}".format(c,letterArray[ord(c) - ord('a')]))
    for c in b :
        print("freq_b[{}]={}".format(c,letterArray[ord(c) - ord('a')]))
    result = 0
    for i in letterArray:
        print("i={}".format(i))
        result += fabs(i)
    return int(result)

a = input().strip()
b = input().strip()

print(number_needed(a, b))


# fcrxzwscanmligyxyvym
# jxwtrhvujlmrpdoqbisbwhmgpmeoke
#
# 30
