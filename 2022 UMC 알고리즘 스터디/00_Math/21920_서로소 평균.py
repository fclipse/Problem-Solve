# 길이가 n인 수열 A에서 X와 서로소인 수들의 평균을 출력하는 프로그램
# 서로소 최소 1개 이상 존재 가정.
# 서로소 정의 : 두 수의 최대공약수가 1인 수
# gcd 알고리즘 이용
import sys
def gcd(p, q):
    if q > p:
        p, q = q, p
    if p % q == 0:
        return q
    else:
        return gcd(q, p%q)

n = int(input())
lst = list(map(int, sys.stdin.readline().split()))
x = int(input())
res = 0
cnt = 0
for i in lst:
    if gcd(i, x) == 1:
        res += i
        cnt += 1
print(res/cnt)