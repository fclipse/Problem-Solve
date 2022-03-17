# 좌표 n개 받아 x좌표 우선, y좌표 다음으로 오름차순 정렬하는 프로그램
import sys

n = int(sys.stdin.readline())
coordinates = []
for i in range(n):
    coordinates.append(list(map(int, sys.stdin.readline().split())))

sorted_lst = sorted(coordinates, key = lambda coordinates:(coordinates[0], coordinates[1]))
for i in sorted_lst:
    print(i[0], i[1])