# 마찬가지 정렬
# 단 n <= 1000000
# 퀵 -> 메모리 초과
import sys

n = int(input())
lst = []
for i in range(n):
    lst.append(int(sys.stdin.readline().strip('\n')))

lst.sort()

for i in lst:
    print(i)