# 덩치
import sys
t = int(input())
people = []
for i in range(t):
    people.append(list(map(int, sys.stdin.readline().split())))

rating = [0] * t
sum = 0
for i in range(t):
    for j in range(t):
        cnt = 0
        for k in range(t):
            if people[k][0] >= people[j][0] and people[k][1] >= people[j][1]:
                cnt += 1
        if cnt - 1 == i:
            rating[j] = i + 1

rating = list(map(str, rating))
print(' '.join(rating))