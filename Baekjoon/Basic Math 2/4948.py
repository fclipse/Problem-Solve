# 베트르랑 공준, 자연수n에 대해 n < k <= 2n인 소수 k는 반드시 존재한다.
import sys, math
while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break
    cnt = 0
    arr = [1] * (2 * n)
    arr[0] = 0
    for i in range(2, int(math.sqrt(2*n))+1):
        if arr[i-1]:            # ** 이게 있어야 에라토스테네스의 체가 제대로 작동함.
            for j in range(2*i, 2*n+1, i):
                arr[j-1] = 0
    
    for i in range(n, 2*n):
        if arr[i]:
            cnt += 1
    print(cnt)