import math


def f(n):
    if (n==0): return 1
    phi_1 = (1+math.sqrt(5))/2
    phi_2 = (1-math.sqrt(5))/2
    return int(1.0/math.sqrt(5)*(math.pow(phi_1,float(n))-math.pow(phi_2,float(n))))

n = input()
print(f(n))
