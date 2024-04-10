import sys
from math import *

def binSearch(n, k, st, ed):
    x = (st + ed) / 2
    smaller_cnt, cnt = smaller_numbers_count(x, n)
    if st == ed:
        if cnt < k:
            return binSearch(n, k, x + 1, ed)
        elif smaller_cnt < k <= cnt:
            return x
        elif smaller_cnt >= k:
            return binSearch(n, k, st, x - 1)

def smaller_numbers_count(x, n):
    cnt = 0
    smaller_cnt = 0
    for i in range(1, n + 1):
        filtered_cnt = min(x // i, i * n)
        cnt += filtered_cnt
        smaller_cnt += filtered_cnt
    
        if i <= x <= i * n and x % i == 0:
            smaller_cnt -= 1
    
    return (smaller_cnt, cnt)


if __name__ == '__main__':
    # n = 10
    # k = 42
    n, k = map(int, sys.stdin.readline().split())
    x = binSearch(n, k, 1, n * n)
    print(x)
