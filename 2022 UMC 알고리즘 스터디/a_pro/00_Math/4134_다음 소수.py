# 베르트랑 공준(4948) -> n과 2n 사이에는 반드시 소수 하나는 존재
# 에라토스테네스의 체도 이용. 단순히 하나하나 계산하려면 시간 너무 많이 듦.
import sys
t = int(input())
for _ in range(t):
    n = int(sys.stdin.readline())
    lst = [0] * (2 * n + 1)
    i = 2
    while i <= 2*n:
        if lst[i] == 0:
            j = i
            if i >= n:
                print(i)
                break
            while j <= 2*n:
                lst[j] = 1
                j += i
        i += 1