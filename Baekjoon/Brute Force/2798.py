# 블랙잭 게임처럼 N장의 카드에 써져 있는 수들로 M이하의 수중 
# M에 최대한 가까운 수를 카드3장의 합을 출력하는 프로그램
import sys
n, m = list(map(int, sys.stdin.readline().split()))
cards = list(map(int, sys.stdin.readline().split()))
max = 0
select = [1, 1, 1] + [0] * (n - 3)
cnt = 0
for i in range(n * (n - 1) * (n - 2) // 6):
    sum = 0
    cnt += 1
    #print(select, cnt)
    for j in range(n):  # 조합의 합 구하기
        if select[j]:
            sum += cards[j]
    if max < sum <= m:
        max = sum # 합이 가장 가까운 수 찾기
    for j in range(n - 2, -1, -1):  # Combination 수동 구현
        if select[j]:
            if select[j + 1] == 0:  # 시프트
                select[j] = 0
                select[j + 1] = 1
                if j + 2 <= n - 1 and 1 in select[j+2:]:    # 리스트 길이 검사, 길이 넘는다 해도 두 번째 조건은 건너뜀.
                    l = select[j+2:].count(1)
                    select[j+2:] = [0] * len(select[j+2:])  # 뒤에 있는 1의 개수만큼 1 넣어줌
                    for k in range(l):
                        select[j+2+k] = 1
                break
    
print(max)