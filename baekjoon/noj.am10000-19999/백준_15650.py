from itertools import *

set = []
n, m = map(int, input().split())

for i in range(1, n+1):
    set.append(i)

for s in combinations(set, m):
    print(*s)