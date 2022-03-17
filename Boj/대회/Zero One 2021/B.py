import sys, math
from decimal import *       ## 큰 자리를 표현할 땐 오차가 생기므로 필요함.
k, n = map(Decimal, sys.stdin.readline().split())
if n == 1:
    print(-1)
else:
    print(math.ceil((k * n) / (n - 1)))