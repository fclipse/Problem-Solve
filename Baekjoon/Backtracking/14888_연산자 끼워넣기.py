# 14888 연산자 끼워넣기
# 백트래킹 idea : 현재 숫자가 max보다 작은데 남은데 //, -밖에 없다면 pass
# 마찬가지로 min보다 큰데 남은게 *, +밖에 없으면 pass
# 그냥 조합 쓰는게 백트래킹효과를 냄.
# https://velog.io/@kimdukbae/BOJ-14888-%EC%97%B0%EC%82%B0%EC%9E%90-%EB%81%BC%EC%9B%8C%EB%84%A3%EA%B8%B0-Python 참고
from itertools import combinations
import sys, copy
n = int(input())
lst = list(map(int, sys.stdin.readline().split()))
oper = list(map(int, sys.stdin.readline().split()))

turn = [-1] * (n-1)
res = lst[0]
res_lst = []

def select(index):
    global turn, res, max, min, res_lst
    if index == 4:
        for i in range(n-1):
            if turn[i] == 0:
                res += lst[i+1]
            elif turn[i] == 1:
                res -= lst[i+1]
            elif turn[i] == 2:
                res *= lst[i+1]
            elif turn[i] == 3:
                if res > 0:
                    res //= lst[i+1]
                else:   # 파이썬에서 음수를 몫나눗셈을 할 경우, -1 // 3 = -1이 나오는 상황이 생긴다.
                    res = -1 * (abs(res) // lst[i+1])
        #print('turn', turn, 'res', res)
        res_lst.append(res)
        res = lst[0]        # 여기서 모르고 0으로 초기화하면 곱하기할때 값이 0이 되버림.
        return

    else:
        if oper[index] > 0:
            turn_save = copy.copy(turn)
            for i in combinations([i for i in range(n-1) if turn[i] == -1], oper[index]):
                for j in i:
                    turn[j] = index
                select(index+1)
                turn = copy.deepcopy(turn_save)
        else:
            select(index+1)
    return
select(0)
#print(res_lst)
print(max(res_lst))
print(min(res_lst))