# 주어진 수 n개 중 소수가 몇 개인지 찾아 출력하는 프로그램
# n <= 100
import sys, math

def prime(p):
    if p == 1:
        return 0
    k = int(math.sqrt(p))   # int 형변환 -> 버림.
    for i in range(2, k+1):
        if p % i == 0:
            return 0
    return 1

n = int(input())
arr = list(map(int, sys.stdin.readline().split()))
cnt = 0
for i in arr:
    if prime(i):
        cnt += 1

print(cnt)