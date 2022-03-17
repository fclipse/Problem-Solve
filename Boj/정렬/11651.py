# 2차원 평면 위의 점 N개가 주어진다. 
# 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
import sys

n = int(sys.stdin.readline())
coordinates = []
for i in range(n):
    coordinates.append(list(map(int, sys.stdin.readline().split())))

sorted_lst = sorted(coordinates, key = lambda coordinates:(coordinates[1], coordinates[0]))
for i in sorted_lst:
    print(i[0], i[1])