# 골드바흐의 추측, 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다.
# 2보다 큰 짝수 n이 주어졌을 때 n의 골드바흐 파티션을 출력하는 프로그램.
# 여러가지일 경우 두 소수 차가 최소인 것 출력.
import sys, math
def prime(p):
    if p == 1:
        return 0
    k = int(math.sqrt(p))   # int 형변환 -> 버림.
    for i in range(2, k+1):
        if p % i == 0:
            return 0
    return 1    

t = int(input())
for i in range(t):
    n = int(sys.stdin.readline())
    k = 0
    while True:
        if prime(n//2 - k) and prime(n//2 + k):
            break
        k += 1
    print(n//2 - k, n//2 + k)