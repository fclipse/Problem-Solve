import math, sys
x, y = map(int, sys.stdin.readline().split())
M = y / x
sum_blocks = 0
for i in range(x):
    sum_blocks += math.ceil(M * (i+1) -int(M * i))
print(sum_blocks)