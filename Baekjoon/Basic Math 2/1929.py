# m 이상 n 이하의 소수를 모두 출력하는 프로그램.
# 에라토스테네스의 체 사용 권장
import math

def prime(p):
    if p == 1:
        return 0
    k = int(math.sqrt(p))   # int 형변환 -> 버림.
    for i in range(2, k+1):
        if p % i == 0:
            return 0
    return 1

m, n = list(map(int, input().split()))
for i in range(m, n+1):
    if prime(i):
        print(i)