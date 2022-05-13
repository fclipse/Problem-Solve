# 호텔 방 배정 프로그램

# 선언부
import sys, math

# 입력부
t = int(input())
for i in range(t):
    h, w, n = list(map(int, sys.stdin.readline().split()))

    # 출력부
    if n % h == 0 :
        print(str(h) + str(math.ceil(n / h)).zfill(2))
    else :
        print(str(n % h) + str(math.ceil(n / h)).zfill(2))