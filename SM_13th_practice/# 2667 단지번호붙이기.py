# 2667 단지번호붙이기
# dfs 풀이 필요.
# 2번째 풀이. 백준에 1번째 풀이 있음. 별 차이는 x
from pydoc import plain
import sys
from collections import deque
n = int(input())
plain_input = []    # 전체 입력받는 지도

for i in range(n):
    plain_input.append(sys.stdin.readline().strip('\n'))
plain_numbers = [[0 for i in range(n)] for j in range(n)]

def dfs(i, j):
    global plain_input, n
    neighbor = []
    stack = deque()
    stack.append([i, j])    # 1인 것들만 들어오므로 바로 추가 가능
    while stack:
        temp = stack.popleft()
        if plain_input[temp[0]][temp[1]] == '1':
            neighbor.append([temp[0], temp[1]])

            if temp[0] > 0 and plain_input[temp[0]-1][temp[1]] == '1' and [temp[0]-1, temp[1]] not in neighbor:    # 위
                stack.appendleft([temp[0]-1, temp[1]])
            if temp[1] > 0 and plain_input[temp[0]][temp[1]-1] == '1' and [temp[0], temp[1]-1] not in neighbor:    # 왼쪽
                stack.appendleft([temp[0], temp[1]-1])
            if temp[0] < n-1 and plain_input[temp[0]+1][temp[1]] == '1' and [temp[0]+1, temp[1]] not in neighbor:  # 아래
                stack.appendleft([temp[0]+1, temp[1]])
            if temp[1] < n-1 and plain_input[temp[0]][temp[1]+1] == '1' and [temp[0], temp[1]+1] not in neighbor:  # 오른쪽
                stack.appendleft([temp[0], temp[1]+1])
    return neighbor # 지역변수, 전역변수 조심

index = 1
for i in range(n):
    for j in range(n):
        cnt = 0
        if plain_input[i][j] == '1' and plain_numbers[i][j]==0:
            temp = dfs(i, j)
            for k in temp:
                plain_numbers[k[0]][k[1]] = index
            index += 1

#for i in plain_numbers:
#    print(i)
print(index - 1)
apt_lst = []
cnt = []

for i in range(1, index):
    cnt = 0
    for j in range(n):
        cnt += plain_numbers[j].count(i)
    apt_lst.append(cnt)
for i in sorted(apt_lst):
    print(i)