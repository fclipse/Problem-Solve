# 23757 고려대 경시대회 2번, 아이들과 선물 상자
# 48min
# 계속 time out 뜸.. 6줄에서 sys.stdin.readline()썼는데도 오류남..
import sys
cnt = 0
n, m = map(int, sys.stdin.readline().split())

present = []        #n개
want = []           #m개
present = list(map(int, sys.stdin.readline().split()))
want = list(map(int, sys.stdin.readline().split()))

if sum(present) < sum(want):
    cnt = -1
# 풀이 : present sort해서 m 동안 반복, present[0] < want[m] 이면 0, 아니면 1
for i in range(m):
    if cnt < 0:
        break
    maxp = max(present)
    if maxp < want[i]:
        break
    else:
        present[present.index(maxp)] -= want[i]
        cnt += 1

# 출력
if cnt == m:
    print('1')
else :
    print('0')