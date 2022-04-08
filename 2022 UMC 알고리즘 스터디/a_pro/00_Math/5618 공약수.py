# 두 수 또는 세 수의 공약수를 모두 출력하는 프로그램
# 최대공약수의 약수는 두 수 사이의 약수임을 이용
# 수가 3개일때는 일단 두 수 사이 최대공약수를 구하고, 세 번째 수와 최대공약수의 최대공약수를 구함.
def gcd(a, b):
    if b > a:
        a, b = b, a
    if a % b == 0:
        return b
    else:
        return gcd(b, a%b)

n = int(input())
lst = list(map(int, input().split()))
GCD = gcd(lst[0], lst[1])
if n == 3:
    GCD = gcd(GCD, lst[2])
for i in range(GCD):
    if GCD % (i+1) == 0:
        print(i+1)