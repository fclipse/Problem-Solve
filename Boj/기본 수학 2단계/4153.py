# 주어진 변의 길이를 가지고 직각삼각형인지를 판별하는 문제
import sys
while True:
    line = list(map(int, sys.stdin.readline().split()))
    if sum(line) == 0:
        break
    line.sort()
    if line[0]**2 + line[1]**2 == line[2]**2:
        print('right')
    else:
        print('wrong')