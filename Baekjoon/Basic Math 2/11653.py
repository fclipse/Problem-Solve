# 정수 n을 소인수분해하는 프로그램
n = int(input())

def factorization(factor, n):
    if n == 1:
        return factor
    for i in range(2, n+1): # n이 소수임을 감안해 루트n까지가 아닌 n 까지 확인해야함
        if n % i == 0:
            factor.append(i)
            return factorization(factor, n//i)

for i in factorization([], n):
    print(i)