# 숫자 10개를 입력받고, 42로 나누었을 때 서로 다른 나머지의 개수 구하기
import sys
arr = []
for i in range(10):
    n = int(sys.stdin.readline()) % 42
    if not (n in arr):
        arr.append(n)

print(len(arr))