import sys
n = int(input())
lst = []
for i in range(n):
    lst.append(list(map(int, sys.stdin.readline().split())))

award = []
for i in range(4):  # i ->과목 번호
    max_score = 0
    scoreboard = []
    for j in range(n):  # j -> 학생 번호
        scoreboard.append([lst[j][i+1], lst[j][0]])   # [[점수, 번호], [점수, 번호], ...] 형식
    scoreboard.sort(reverse=True)
    print(scoreboard)
    # award 받을 학생 탐색
    for j in range(n):
        if scoreboard[j][1] not in award:
            k = j
            same = [scoreboard[j][1]]
            while scoreboard[k][0] == scoreboard[k+1][0]:
                if scoreboard[k+1][1] not in award:
                    same.append(scoreboard[k+1][1])
                k += 1
                if k >= n - 1:
                    break
            same.sort()
            print(same)
            award.append(same[0])
            break
    #print(award)
for i in range(4):
    print(award[i], end = ' ')