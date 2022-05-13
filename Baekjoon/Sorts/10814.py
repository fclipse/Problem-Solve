# 나이와 이름을 입력받아 나이순, 선착순으로 정렬하는 프로그램
import sys
n = int(input())
clients = []
for i in range(n):
    clients.append(sys.stdin.readline().split())
for i in clients:
    i[0] = int(i[0])

clients.sort(key = lambda clients : clients[0])

for i in clients:
    print(i[0], i[1])