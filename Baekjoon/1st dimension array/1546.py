# 입력받은 과목 수대로 성적을 입력받고, 점수 / M * 100으로 고친 뒤 새로운 평균을 출력하는 문제
import sys  # 입력 빨리 받게 해주는거 
subjects = []

# 입력부
n = int(input())
subjects = list(map(int, sys.stdin.readline().split()))     # map 한 뒤 list로 변환 필요
M = max(subjects)

# 연산부
for i in range(n):
    subjects[i]  *= 100 / M
average = sum(subjects) / n

#출력부
print(average)