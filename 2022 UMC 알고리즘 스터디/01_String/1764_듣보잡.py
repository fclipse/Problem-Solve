# 두 집합에 모두 존재하는 문자를 출력하는 프로그램
# set 자료형의 교집합 연한을 통해 쉽게 구현함.
import sys
n, m = map(int, input().split())
hear = set()
see = set()
for i in range(n):
    hear.add(sys.stdin.readline().strip('\n'))
for i in range(m):
    see.add(sys.stdin.readline().strip('\n'))
hear_see = sorted(list(hear & see))
print(len(hear_see))
for j in hear_see:
    print(j)