# 지뢰찾기

# 입력부
matrix = []
x, y = list(map(int, input().split()))
for i in range(x):
    matrix.append(list(input()))

# 연산부
for i in range(y):
    for j in range(x):
        if matrix[i][j] == '.':
            sum = 0
            for p in range(-1, 2):
                if 0 <= i + p < y:
                    for q in range(-1, 2):
                        if 0 <= j + q < x :
                            if matrix[i+p][j+q] == '*':
                                sum += 1
            matrix[i][j] = sum

# 출력부
for i in range(y):
    for j in range(x):
        print(matrix[i][j], end = '')
    print('')