from math import *

n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    print(int(factorial(b)/(factorial(a)*factorial(b-a))))