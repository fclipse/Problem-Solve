import sys
n = int(input())
def gcd(a, b):
    if a < b:
        a, b = b, a
    if a % b == 0:
        return b
    else:
        return gcd(b, a%b)

for i in range(n):
    n1, n2 = map(int, sys.stdin.readline().split())
    print(int(n1*n2/gcd(n1, n2)))