# 7576 토마토_ver.2
import sys
from collections import deque
m, n = map(int, sys.stdin.readline().split())
lst = []
success = 0
cnt = 0
delay = 0
for i in range(n):
    lst.append(list(map(int, sys.stdin.readline().split())))

queue = deque()
queue_chk = [[0 for j in range(m)]for i in range(n)]

for i in range(n):
    for j in range(m):
        if lst[i][j] == 1 and queue_chk[i][j] == 0:
            queue.append((i, j))
            queue_chk[i][j] = 1

delay = len(queue)
while queue:
    temp = queue.popleft()
    delay -= 1
    
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
    if temp[1] < m-1 and lst[temp[0]][temp[1]+1] == 0 and queue_chk[temp[0]][temp[1]+1] == 0:
        queue.append((temp[0], temp[1]+1))
        queue_chk[temp[0]][temp[1]+1] = 1
    
    if delay == 0:
        cnt += 1
        delay = len(queue)

for i in range(n):
    if 0 in lst[i]:
        success = -1
        break
    
if success == -1:
    print(-1)
else:
    print(cnt-1)