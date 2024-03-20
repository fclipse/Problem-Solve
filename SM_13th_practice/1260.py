import sys
from collections import deque

def dfs(graph, root):
    visited = []
    stack = deque([root])
    while stack:
        n = stack.popleft()
        if n not in visited:
            visited.append(n)
            stack.extendleft(reversed([i for i in graph[n] if i not in visited]))
    for i in visited:
        print(i, end = ' ')
    return

def bfs(graph, root):
    visited = []
    queue = deque([root])
    while queue:
        n = queue.popleft()
        if n not in visited:
            visited.append(n)
            queue += [i for i in graph[n] if i not in visited]
    for i in visited:
        print(i, end = ' ')
    return visited


n, m, v = map(int, sys.stdin.readline().split())
#print(n, m, v)
node = {}

for i in range(m):
    n1, n2 = map(int, sys.stdin.readline().split())
    
    if n1 not in node:  # n1이 노드에 없을 때 추가
        node[n1] = [n2]
    elif n2 not in node[n1]:    # n1이 노드에 있고 그 안에 n2가 없을 때
        node[n1].append(n2)
    
    if n2 not in node:
        node[n2] = [n1]
    elif n1 not in node[n2]:
        node[n2].append(n1)

for i in node.keys():
    node[i].sort()
#print(node)

dfs(node, v)
print()
bfs(node, v)