# 직사각형의 모서리까지 가는 거리의 최솟값을 구하는 프로그램
import sys
x, y, w, h = list(map(int, sys.stdin.readline().split()))
print(min(min(x, w-x), min(y, h-y)))