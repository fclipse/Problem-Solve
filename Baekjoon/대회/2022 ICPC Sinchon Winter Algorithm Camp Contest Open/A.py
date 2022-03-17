import sys
n = int(input())
max = 0
for i in range(n):
    line = sys.stdin.readline()
    cnt = line.count('while') + line.count('for')
    if cnt > max:
        max = cnt
print(max)