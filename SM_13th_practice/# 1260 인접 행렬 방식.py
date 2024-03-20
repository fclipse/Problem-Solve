# 1260 인접 행렬 방식
import sys
from collections import deque

n, m, v = map(int, sys.stdin.readline().split())    # 노드개수, 간선개수, 시작노드
node = [[0] * (n+1) for i in range(n+1)]            # 인접행렬방식으로 노드간 연결 저장.

for i in range(m):  # 간선 m개므로 m번 반복
    n1, n2 = map(int, sys.stdin.readline().split()) # 양방향으로 연결된 두 노드
    
    if node[n1][n2] == 0:
        node[n1][n2] = 1
    if node[n2][n1] == 0:
        node[n2][n1] = 1
#print(node)

def dfs(graph, root):   # graph와 root로 node와 v를 받음.
    global n        # 전체 노드의 개수
    visited = []    # 방문한 노드를 기록하는 변수
    stack = deque([root])   # deque 자료형 사용, ordered로 순서는 저장됨.
    
    while stack:
        temp = []           # extendleft()사용하면 리스트가 뒤집혀서 들어가 temp에 임시저장한 후 붙여넣음.
        #print(stack)
        val = stack.popleft()   # stack 왼쪽에서 자료가 출입함.

        if val not in visited:
            visited.append(val) # 방문 추가
            for i in range(1, n+1):
                if graph[val][i] == 1 and i not in visited:  # 방문은 하지 않았지만 stack에 있어서 stack에 다시 추가되는 경우 방지
                    temp.append(i)
            stack = deque(temp) + stack # 왼쪽으로 집어넣기 위함. 위에서 설명한대로 순서 뒤집힘 방지를 위해 이렇게 함.
            #print(stack)
    # 다 끝난 후 출력
    for i in visited:
        print(i, end = ' ')
    return

def bfs(graph, root):
    global n
    visited = []
    queue = deque([root])
    while queue:
        val = queue.popleft()   # 오른쪽으로 들어가서 왼쪽으로 나옴.
        if val not in visited:
            visited.append(val)
            for i in range(1, n+1):
                if graph[val][i] == 1 and i not in visited:
                    queue.append(i) # 여긴 queue이므로 바로 집어넣어도 순서 상관없음. 
    for i in visited:
        print(i, end = ' ')
    return

dfs(node, v)
print()
bfs(node, v)