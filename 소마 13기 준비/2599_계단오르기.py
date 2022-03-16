# 2599 - 계단 오르기
# dfs 조지고 DP로 풀이
import sys
n = int(sys.stdin.readline())
stairs = []
for i in range(n):
    stairs.append(int(sys.stdin.readline()))

lst = [0] * n
lst[0] = stairs[0]
# n이 1이거나 2일 수도 있음.
if n > 1:
    lst[1] = max(stairs[0]+stairs[1], stairs[1])
if n > 2:
    lst[2] = max(stairs[1]+stairs[2], stairs[0]+stairs[2])

for i in range(3, n):
    lst[i] = max(lst[i-2] + stairs[i], lst[i-3] + stairs[i-1] + stairs[i])
print(lst[-1])