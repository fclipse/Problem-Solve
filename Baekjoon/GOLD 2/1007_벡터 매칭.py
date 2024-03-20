import sys, math#, time
from itertools import permutations
from itertools import combinations
from collections import deque
#st = time.time()
t = int(input())
success = 0

def matching(sum_x, sum_y):
    global coordinates, distance, n, nodes, success
    length = len(nodes)
    if length == 0:
        distance.append(math.sqrt(sum_x**2 + sum_y**2))
        if distance[-1] == 0:
            success = 1
        return
    else:
        root = nodes.popleft()
        for i in range(length-1):
            if success:
                return
            temp = nodes[i]
            del nodes[i]
            # root방향 벡터일때
            sum_x += coordinates[root][0] - coordinates[temp][0]
            sum_y += coordinates[root][1] - coordinates[temp][1]
            matching(sum_x, sum_y)
            sum_x -= coordinates[root][0] - coordinates[temp][0]
            sum_y -= coordinates[root][1] - coordinates[temp][1]
            
            # temp방향 벡터일 때
            sum_x += coordinates[temp][0] - coordinates[root][0]
            sum_y += coordinates[temp][1] - coordinates[root][1]
            matching(sum_x, sum_y)
            sum_x -= coordinates[temp][0] - coordinates[root][0]
            sum_y -= coordinates[temp][1] - coordinates[root][1]
            nodes.insert(i, temp)
        nodes.appendleft(root)
    return

for i in range(t):
    n = int(input())
    coordinates = []
    distance = []
    for j in range(n):
        coordinates.append(list(map(int, sys.stdin.readline().split())))
    nodes = deque([i for i in range(n)])
    matching(0, 0)
    #print(distance)
    print(min(distance))
    #print('time :', time.time() - st, 's')