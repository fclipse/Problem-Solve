import sys
from itertools import combinations
def gcd(p, q):
    if q > p:
        p, q = q, p
    if p % q == 0:
        return q
    else:
        return gcd(q, p%q)
t = int(input())
for _ in range(t):
    lst = list(map(int, sys.stdin.readline().split()))
    lst.pop(0)
    ans = []
    for a, b in combinations(lst, 2):
        GCD = gcd(a, b)
        ans.append(GCD)
    print(sum(ans))