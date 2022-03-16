# 1932 정수 삼각형
import sys
n = int(input())
triangle = []
for i in range(n):
    triangle.append(list(map(int, sys.stdin.readline().split())))
#print(triangle)

pos = [[0]*i for i in range(1, n+1)]
pos[0][0] = triangle[0][0]
#print(pos)
for i in range(n):
    for j in range(i+1):
        if i > 0:
            if 0 < j < i:
                pos[i][j] = max(pos[i-1][j], pos[i-1][j-1]) + triangle[i][j]
            elif j == 0:
                pos[i][j] = pos[i-1][j] + triangle[i][j]
            else:
                pos[i][j] = pos[i-1][j-1] + triangle[i][j]
print(max(pos[n-1]))