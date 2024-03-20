# Fly me to the Alpha Centauri
## 알고리즘 : 
# 1. 피라미드 모양의 n까지의 합은 n**2
# 2. 만약 n**2 < distance < (n+1)**2 일때(같은경우는 제외) n**2와 (n+1)**2의 차이는 2n+1
# 따라서 둘 사이 최대 간격은 2*n임.
# 3. 만약 나머지(distance - n**2)가 n이하면 한 턴만 추가해도 가능.
# 4. 만약 나머지가 n초과면 두 턴 이상 추가해야함. 2*n인 경우까지 두턴만 추가해도 가능.

import sys

num = int(input())
for i in range(num):
    a, b = list(map(int, sys.stdin.readline().split()))
    distance = b - a
    n = 1
    while n**2 <= distance:
        n += 1
    n -= 1  # n**2 < distance < (n+1)**2 로 만들어주는 수식
    
    if n**2 == distance:
        print(2*n-1)
    else:
        remain = distance - n**2
        if remain <= n:
            print(2*n)
        else:
            print(2*n + 1)