# 체스말 있으면 -1, 못 놓으면 1 이상
import time

n = int(input())
st = time.time()

board = [[0 for j in range(n)] for i in range(n)]
cnt = 0
queens = 0

def print_board():
    for i in range(n):
        print('p', ' '.join(map(str, board[i])))
    print('queens :', queens)
    print()
    return

def check(y, x):
    global board
    k = 0
    for i in range(n):  # 가로, 세로
        if board[i][x] != 0 or board[y][i] != 0:
            return 0
    # 오른쪽 아래로
    if y - x >= 0:
        for i in range(n - (y - x)):
            if board[y-x + i][i] != 0:
                if y != y-x+i and x != i:
                    return 0
    else:
        for i in range(n - (x-y)):
            if board[i][x-y+i] != 0:
                if y != i and x != x-y+i:
                    return 0
    # 왼쪽 아래로
    if x + y <= n - 1:
        for i in range(x+y+1):
            if board[i][x+y - i] != 0:
                if y != i and x+y - i != x:
                    return 0
    else:
        for i in range(2*n - 1 - (x+y)):
            if board[x+y- n + 1 + i][n - 1 - i] != 0:
                if y != x+y- n + 1 + i and x != n - 1 - i:
                    return 0
    return 1    # 가능

def mark(i, j):
    for k in range(n):
        if k != i and board[k][j] >= 0:
            board[k][j] += 1
        if k != j and board[i][k] >= 0:
            board[i][k] += 1
    # 오른쪽 아래로
    if i - j >= 0:
        for k in range(n - (i - j)):
            if board[i-j + k][k] >= 0 and k != j:
                board[i-j + k][k] += 1
    else:
        for k in range(n - (j-i)):
            if board[k][j-i+k] >= 0 and k != i:
                board[k][j-i+k] += 1

    # 왼쪽 아래로
    if j + i <= n - 1:
        for k in range(j+i+1):
            if board[k][j+i - k] >= 0 and k != i:
                board[k][j+i - k] += 1
    else:
        for k in range(2*n - 1 - (j+i)):
            if board[j+i- n + 1 + k][n - 1 - k] >= 0 and n - 1 - k != j:
                board[j+i- n + 1 + k][n - 1 - k] += 1
    return

def unmark(i, j):
    for k in range(n):
        if k != i and board[k][j] >= 0:
            board[k][j] -= 1
        if k != j and board[i][k] >= 0:
            board[i][k] -= 1
    # 오른쪽 아래로
    if i - j >= 0:
        for k in range(n - (i - j)):
            if board[i-j + k][k] >= 0 and k != j:
                board[i-j + k][k] -= 1
    else:
        for k in range(n - (j-i)):
            if board[k][j-i+k] >= 0 and k != i:
                board[k][j-i+k] -= 1

    # 왼쪽 아래로
    if j + i <= n - 1:
        for k in range(j+i+1):
            if board[k][j+i - k] >= 0 and k != i:
                board[k][j+i - k] -= 1
    else:
        for k in range(2*n - 1 - (j+i)):
            if board[j+i- n + 1 + k][n - 1 - k] >= 0 and n - 1 - k != j:
                board[j+i- n + 1 + k][n - 1 - k] -= 1
    return

def n_queen(i, j):
    global cnt
    global board
    global queens

    for k in range(n**2):
        if (i*n+j+k)//n >= n:
            return # 보드 끝까지 갔을 때 -> 실패 
        #if check((i*n+j+k)//n, (j+k)%n) == 1 and board[(i*n+j+k)//n][(j+k)%n] == 0:
        if board[(i*n+j+k)//n][(j+k)%n] == 0:
            board[(i*n+j+k)//n][(j+k)%n] = -1
            queens += 1     # queen 추가
            mark((i*n+j+k)//n, (j+k)%n)
            
            if queens == n: # 완성 되었을 때
                cnt += 1
                #print('complete')
                #print_board()

                queens -= 1
                board[(i*n+j+k)//n][(j+k)%n] = 0
                unmark((i*n+j+k)//n, (j+k)%n)
                continue

            next_j = (j+k)%n + 1
            next_i = (i*n+j+k)//n
            if next_j == n:
                next_i += 1
                next_j = 0
            if next_i >= n: # 보드 끝까지 갔을 때 -> 실패

                queens -= 1
                board[-1][-1] = 0
                unmark((i*n+j+k)//n, (j+k)%n)     
                return  # end

            n_queen(next_i, next_j)

            queens -= 1
            board[(i*n+j+k)//n][(j+k)%n] = 0
            unmark((i*n+j+k)//n, (j+k)%n)
    
    return

n_queen(0, 0)
#print(board)
print(cnt)
print("time:", time.time() - st)