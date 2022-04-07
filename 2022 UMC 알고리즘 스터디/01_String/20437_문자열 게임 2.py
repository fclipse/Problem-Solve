# 각 알파벳의 위치를 딕셔너리로 저장
# 3번규칙은 한 알파벳 종류 안에서 위치의 차가 가장 작은 조합을
# 4번규칙은 위치 차가 가장 큰 조합을 구하는 것
# 위치 차를 구했으니까 마지막에 1 더해줘야함(그 자리까지 포함)
import sys
t = int(input())
for _ in range(t):
    cnt = 0
    w = sys.stdin.readline().strip('\n')
    k = int(sys.stdin.readline().strip('\n'))
    MIN = len(w)
    MAX = 0
    location = dict(zip((chr(i) for i in range(ord('a'), ord('z')+1)), ([] for i in range(26))))
    for i, word in enumerate(w):
        location[word].append(i)
    for i in location:
        if len(location[i]) >= k:
            cnt = 1
            for j in range(len(location[i]) - k + 1):
                if MIN > location[i][j+k-1] - location[i][j]:
                    MIN = location[i][j+k-1] - location[i][j]
                if MAX < location[i][j+k-1] - location[i][j]:
                    MAX = location[i][j+k-1] - location[i][j]
    if cnt == 0:
        print(-1)
    else:
        print(MIN+1, MAX+1)