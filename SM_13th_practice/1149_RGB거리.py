# 1149 - RGB거리
import sys
n = int(input())
cost = []
for i in range(n):
    cost.append(list(map(int, sys.stdin.readline().split())))
#print(cost)

red = [0] * n
green = [0] * n
blue = [0] * n

red[0] = cost[0][0]
green[0] = cost[0][1]
blue[0] = cost[0][2]

for i in range(1, n):
    red[i] = cost[i][0] + min(green[i-1], blue[i-1])
    green[i] = cost[i][1] + min(red[i-1], blue[i-1])
    blue[i] = cost[i][2] + min(green[i-1], red[i-1])
print(min(min(red[n-1], green[n-1]), blue[n-1]))