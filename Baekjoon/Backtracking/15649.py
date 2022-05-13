# 순열 사용
from itertools import permutations
n, m = map(int, input().split())
for i in permutations(range(1, n+1), m):
    for j in range(m):
        print(i[j], end = ' ')
    print()