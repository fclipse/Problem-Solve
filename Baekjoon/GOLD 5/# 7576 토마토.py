# 7576 토마토
import sys
from collections import deque
m, n = map(int, sys.stdin.readline().split())
lst = []
success = 0
cnt = 0
for i in range(n):
    lst.append(list(map(int, sys.stdin.readline().split())))
queue_chk = [[0 for i in range(m)] for j in range(n)]
# queue_chk 출력
"""
for i in range(n):
    print(queue_chk[i])
"""
# 처음에 1이 들어 있는 곳에서 시작.
queue = deque()
for i in range(n):
    for j in range(m):
        if lst[i][j] == 1 and queue_chk[i][j] == 0:
            queue.append((i, j))
            queue_chk[i][j] = 1

# 처음에 1이 들어 있는 장소에서 주변 노드들을 추가해줌. 이건 count x
delay = len(queue)
for i in range(delay):
    temp = queue.popleft()
    if temp[0] > 0 and lst[temp[0]-1][temp[1]] == 0 and queue_chk[temp[0]-1][temp[1]] == 0:
        queue.append((temp[0]-1, temp[1]))
        queue_chk[temp[0]-1][temp[1]] = 1
    if temp[1] > 0 and lst[temp[0]][temp[1]-1] == 0 and queue_chk[temp[0]][temp[1]-1] == 0:
        queue.append((temp[0], temp[1]-1))
        queue_chk[temp[0]][temp[1]-1] = 1
    if temp[0] < n-1 and lst[temp[0]+1][temp[1]] == 0 and queue_chk[temp[0]+1][temp[1]] == 0:
        queue.append((temp[0]+1, temp[1]))
        queue_chk[temp[0]+1][temp[1]] = 1
    if temp[1] < n-1 and lst[temp[0]][temp[1]+1] == 0 and queue_chk[temp[0]][temp[1]+1] == 0:
        queue.append((temp[0], temp[1]+1))
        queue_chk[temp[0]][temp[1]+1] = 1
    
    delay -= 1
    
# bfs 구현
while queue:
    # tree의 각 계층에 있는 노드들의 개수를 delay에 담고 매번 -= 1을 해주어
    # tree의 한 층을 돌 때마다 cnt += 1을 해줌
    if delay == 0:
        cnt += 1
        delay = len(queue)
    delay -= 1
    temp = queue.popleft()
    lst[temp[0]][temp[1]] = 1
    
    if temp[0] > 0 and lst[temp[0]-1][temp[1]] == 0 and queue_chk[temp[0]-1][temp[1]] == 0:
        queue.append((temp[0]-1, temp[1]))
        queue_chk[temp[0]-1][temp[1]] = 1
    if temp[1] > 0 and lst[temp[0]][temp[1]-1] == 0 and queue_chk[temp[0]][temp[1]-1] == 0:
        queue.append((temp[0], temp[1]-1))
        queue_chk[temp[0]][temp[1]-1] = 1
    if temp[0] < n-1 and lst[temp[0]+1][temp[1]] == 0 and queue_chk[temp[0]+1][temp[1]] == 0:
        queue.append((temp[0]+1, temp[1]))
        queue_chk[temp[0]+1][temp[1]] = 1
    if temp[1] < n-1 and lst[temp[0]][temp[1]+1] == 0 and queue_chk[temp[0]][temp[1]+1] == 0:
        queue.append((temp[0], temp[1]+1))
        queue_chk[temp[0]][temp[1]+1] = 1
    
    """
    print('cnt :', cnt, 'location', temp[0], temp[1])
    for i in range(n):
        print(lst[i])
    print(queue)
    print()
    """

for i in range(n):
    if 0 in lst[i]:
        success = -1
        break

if success == -1:
    print(-1)
else:
    print(cnt)