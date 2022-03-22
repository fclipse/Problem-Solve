# 하나라도 음수면 1
# 하나라도 20 초과면 w(20, 20, 20)
# a < b, b < c이라면 w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
# 아니면 w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

# IDEA : 삼차원 배열을 사용해 구한 값은 저장하고, 값이 있으면 그 값을 불러옴.
import sys
def w(a, b, c):
    global lst
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)
    elif lst[a][b][c] != 0:
        return lst[a][b][c]
    elif a < b and b < c:
        lst[a][b][c-1] = w(a, b, c-1)
        lst[a][b-1][c-1] = w(a, b-1, c-1)
        lst[a][b-1][c] = w(a, b-1, c)
        return lst[a][b][c-1] + lst[a][b-1][c-1] - lst[a][b-1][c]
    else:
        lst[a-1][b][c] = w(a-1, b, c)
        lst[a-1][b-1][c] = w(a-1, b-1, c)
        lst[a-1][b][c-1] = w(a-1, b, c-1)
        lst[a-1][b-1][c-1] = w(a-1, b-1, c-1)
        return lst[a-1][b][c] + lst[a-1][b-1][c] + lst[a-1][b][c-1] - lst[a-1][b-1][c-1]

while True:
    a, b, c = map(int, sys.stdin.readline().split())
    if a == b and b == c and a == -1:
        break
    lst = [[[0 for i in range(21)] for j in range(21)] for k in range(21)]  # 굳이 50이 아니라 0~20까지만 저장하면 됨.
    print('w(' + str(a) + ', ' + str(b) + ', ' + str(c) + ') = ' + str(w(a, b, c)))