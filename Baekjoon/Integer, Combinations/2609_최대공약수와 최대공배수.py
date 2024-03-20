# 두 수를 입력받고 그 수들의 최대공약수와 최소공배수를 출력하는 문제
def gcd(a, b):
    b, a = sorted([a, b])
    #print(a, b)
    if a % b == 0:
        return b
    else:
        return gcd(b, a%b)

p, q = map(int, input().split())
GCD = gcd(p, q)
print(GCD)
print(p * q // GCD)