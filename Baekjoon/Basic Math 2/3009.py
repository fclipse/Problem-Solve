# 직사각형의 네 점 좌표를 완성하는 문제
# IDEA : 계수정렬; x1, y1, x2, y2 총 4개의 좌표로 구성되므로
# 3개의 점에서 x, y좌표가 각각 2번씩 나온 걸 제외하고 1번씩만 나온 좌표를 구한다.
# 좌표 4개(x1, y1, x2, y2)가 각각 2번식 이용되어야 한다는 것을 이용한 알고리즘.
import sys
xs = []
ys = []
for i in range(3):
    x, y = list(map(int, sys.stdin.readline().split()))
    xs.append(x)
    ys.append(y)

xs.sort()
ys.sort()
answer = [0, 0]
for i in range(3):
    if xs.count(xs[i]) == 1:
        answer[0] = xs[i]  
    if ys.count(ys[i]) == 1:
        answer[1] = ys[i]

print(answer[0], answer[1])