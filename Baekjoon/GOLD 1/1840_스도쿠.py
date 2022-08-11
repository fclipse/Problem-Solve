# 1840, 언제 사용자가 실수를 했는 지 출력하는 프로그램
import sys
sudoku = [[[k for k in range(1, 10)] for j in range(9)] for i in range(9)]
#print(sudoku[0][0])
fail = 0

for _ in range(81):
    if fail:
        break
    i, j, n = map(int, sys.stdin.readline().split())
    i -= 1
    j -= 1
    sudoku[i][j] = [n]
    for l in range(9):
        # 세로줄 검사
        if l != i:
            if n in sudoku[l][j]:
                sudoku[l][j].remove(n)
                if len(sudoku[l][j]) == 0:
                    print(_ + 1)
                    fail = 1
                    break
        # 가로줄 검사
        if l != j:
            if n in sudoku[i][l]:
                sudoku[i][l].remove(n)
                if len(sudoku[i][l]) == 0:
                    print(_ + 1)
                    fail = 1
                    break
        if i//3*3 + l//3 != i and i%3*3 + l%3 != j:
            if n in sudoku[i//3*3 + l//3][i%3*3 + l%3]:
                sudoku[i//3*3 + l//3][i%3*3 + l%3].remove(n)
                if len(sudoku[i//3*3 + l//3][i%3*3 + l%3]) == 0:
                    print(_ + 1)
                    fail = 1
                    break
    
if fail == 0:
    print(-1)