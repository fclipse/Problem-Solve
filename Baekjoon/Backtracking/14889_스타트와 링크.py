# 팀을 어떤 조합으로 짤 수 있는지를 알아보는 알고리즘
# 조합 사용했지만 백트래킹 재귀함수로도 풀어보기
from itertools import combinations
import sys
n = int(input())
status = []
for i in range(n):
    status.append(list(map(int, sys.stdin.readline().split())))

diff = []
for start_team in combinations(range(n), n//2):
    start_stat = 0
    link_stat = 0
    link_team = tuple(i for i in range(n) if i not in start_team)
    for i in start_team:
        for j in start_team:
            start_stat += status[i][j]
    for i in link_team:
        for j in link_team:
            link_stat += status[i][j]
    diff.append(abs(start_stat - link_stat))
print(min(diff))