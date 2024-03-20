# C번의 케이스마다 N명의 학생들의 점수를 입력받고, 
# 그중 평균 초과인 사람의 비율을 출력하는 문제
# 소숫점 아래 자릿수를 얼마까지 표현하는게 힘들었음.

# 선언부
import sys

# 입력부
c = int(sys.stdin.readline())
arr = []
n = 0
ave = 0

# 연산출력부
for i in range(c):
    arr = list(map(int, sys.stdin.readline().split()))
    n = arr.pop(0)
    ave = sum(arr) / n
    cnt = 0
    for j in arr:
        if j > ave:
            cnt += 1
    ans = cnt / n * 100       # 반올림 -> round 함수
    
    print(f'{ans:.3f}' + '%')   #f-string형식으로 내가 원하는 만큼 소숫점 아래 자릿수 표현 가능.