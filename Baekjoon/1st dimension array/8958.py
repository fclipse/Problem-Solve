# 입력된 숫자의 줄만큼 O와 X가 입력됨.
# O는 1점, X는 0점
# O가 연속되면 다음 O의 점수는 이전 O 점수에 1점을 더함.

# 선언부
import sys

# 입력부
n = int(input())
arr = []
for i in range(n):
    arr.append(sys.stdin.readline())

# 연산 출력부
for i in range(n):
    cnt = 0
    sum = 0
    for j in arr[i]:
        if j == 'O' :
            cnt += 1
            sum += cnt
        else :
            cnt = 0
    print(sum)
