# 연속되는 n에 대해 가장 많은 소수를 만들어내는 이차식
import math
def prime(n):
    for i in range(2, int(math.sqrt(abs(n))) + 1):
        if n % i == 0:
            return 0
    return 1

def f(a, b, n):
    return n**2 + a*n + b

cnt = 0
max = 0
pair = []
for a in range(-999, 1000):
    for b in range(-999, 1000):
        cnt = 0
        n = 0
        while True:
            if prime(f(a, b, n)) == 0:
                break
            n += 1
            cnt += 1
        if max < cnt:
            max = cnt
            pair = [a, b]
    if a % 100 == 0:
        print(a)
print(pair, max)
print(pair[0] * pair[1])