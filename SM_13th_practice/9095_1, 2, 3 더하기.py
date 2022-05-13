# 9095 1, 2, 3 더하기
import sys
n = int(input())
x = 0

for i in range(n):
    lst = [0]
    x = int(sys.stdin.readline())
    lst *= x + 1
    lst[0] = 1
    if x > 1:
        lst[1] = 2
    if x > 2:
        lst[2] = 4
    if x > 3:
        lst[3] = 7
    for j in range(4, x):
        lst[j] = lst[j-1] + lst[j-2] + lst[j-3]
    print(lst[x-1])