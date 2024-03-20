# 아파트의 k층 n호에 몇 명이 살고 있는지 출력하는 프로그램
# 선언부
import sys

# 입력부
t = int(input())
for _ in range(t):
    k = int(sys.stdin.readline().strip('\n'))
    n = int(sys.stdin.readline().strip('\n'))
    
    # 연산부
    matrix = [[0 for i in range(n)] for j in range(k + 1)]
    for i in range(n):
        matrix[0][i] = i + 1        #0층 i호는 i명이 산다

    for i in range(k + 1):
        for j in range(n):
            sum = 0
            if matrix[i][j] == 0:
                for l in range(j+1):
                    sum += matrix[i-1][l]
                matrix[i][j] = sum
    # 예비출력
    #for i in range(k + 1):
    #    print(matrix[k - i])
    print(matrix[k][n - 1])