# m이상 n이하의 자연수 중 소수인 것들의 합과 최솟값을 출력하는 프로그램
import sys, math

def prime(p):
    if p == 1:
        return 0
    k = int(math.sqrt(p))   # int 형변환 -> 버림.
    for i in range(2, k+1):
        if p % i == 0:
            return 0
    return 1

m = int(input())
n = int(input())

arr = []
for i in range(m, n+1):
    if prime(i):
        arr.append(i)

if len(arr) == 0:
    print(-1)
else:
    print(sum(arr))
    print(arr[0])