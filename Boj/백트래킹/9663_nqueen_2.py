# 9663 nQueen, 좌표 간소화 버전
# 1차원 배열에 각 칸의 y좌표를 집어넣는 방식으로 좌표 간소화 가능. 이러면 굳이 세로칸 검사 안해도 있는지 없는지 O(1)만에 확인 가능
# 대각선이랑 가로 검사할 때 현재 칸의 좌측만 확인하면 됨. 나머지 칸들은 볼 필요 x
# 
n = int(input())
cnt = 0
board = [-1] * n
#print(board)
def backtracking(index):
    global board, n, cnt
    if index < n:
        board[index] = -1
    else:
        cnt += 1
        #print(board)
        board[-1] = -1
        return
    for i in range(n):
        if i not in board[:index]:
            diagonal_ck = 0
            for j in range(index):  # 대각선 체크, 이거 굳이 다 볼 필요 없음. 좌에서 우로 가니까 현재 칸보다 좌측만 확인하면 됨.
                if j != index and abs(j - index) == abs(board[j] - i) and board[j] >= 0:
                    diagonal_ck += 1
                    break
            if diagonal_ck == 0:
                board[index] = i
                backtracking(index + 1)
    return

backtracking(0)
print(cnt)
