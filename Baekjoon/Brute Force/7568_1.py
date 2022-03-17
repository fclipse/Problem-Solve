# 덩치의 순위를 매기는 프로그램
# 단순하게 문제에 써진 대로 자신보다 큰 사람의 수 + 1 한 값을
# 출력하면 되는 문제였음.
# 괜히 위에 있는 순위 개수 셀 필요 없이..
import sys

n = int(input())
people = []
for i in range(n):
    people.append((list(map(int, sys.stdin.readline().split()))))

bigger = [0] * n
for i in range(n):
    for j in range(n):
        if i != j:
            if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
                bigger[i] += 1

for i in bigger:
    print(i + 1, end = ' ')