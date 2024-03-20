import sys, copy
from itertools import permutations
# 선 두개에서 하나의 선을 기준으로 잡고, 다른 선의 두 점을 함수에 대입해
# 나온 결과의 곱이 양수면 겹치지 않는것. 음수면 겹침.
def cross(sx, sy, ex, ey, x, y):
    m = (ey - sy) / (ex - sx)
    # 점이 선 아래에 있는 것.
    if m*(x - sx) + sy > y:
        return -1
    else:
        return 1
# 입력부
n = int(sys.stdin.readline())
lines = []
relations = [[0 for j in range(n)] for i in range(n)]
for i in range(n):
    lines.append(list(map(int, sys.stdin.readline().split())))

# relations 초기설정.
i = 0
j = 0
while i < n:
    while j < n:
        if i == j:
            j += 1
            continue
        # 겹치면 변경
        if cross(lines[i][0], lines[i][1], lines[i][2], lines[i][3], lines[j][0], lines[j][1]) * cross(lines[i][0], lines[i][1], lines[i][2], lines[i][3], lines[j][2], lines[j][3]) < 0:
            relations[i][j] = 1
            relations[j][i] = 1
        j += 1
    i += 1

c_relations = []
turns = permutations(range(n), n)
min_res = -1
# Brute Force
for turn in turns:
    c_relations = copy.deepcopy(relations)
    res = 0
    # 한 경우에서의 내공의 합 구하기
    for i in turn:
        cnt = 0
        for j in range(n):
            if c_relations[i][j]:
                cnt += 1
                c_relations[i][j] = 0
                c_relations[j][i] = 0
        res += (1+cnt) * lines[i][4]
    if res < min_res or min_res < 0:
        min_res = res
print(min_res)