# n개의 케이스에서 두 수를 입력받아 최소공배수를 출력하는 프로그램
# 최대공약수 * 최소공배수 = 두 수의 곱 이라는 공식 이용.
import sys
def gcd(p, q):
    if q > p:
        p, q = q, p
    if p % q == 0:
        return q
    else:
        return gcd(q, p%q)

n = int(input())

for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    print(a * b // gcd(a, b))