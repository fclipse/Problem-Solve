# 14888 연산자 끼워넣기
# 백트래킹 idea : 현재 숫자가 max보다 작은데 남은데 //, -밖에 없다면 pass
# 마찬가지로 min보다 큰데 남은게 *, +밖에 없으면 pass
import sys, math
n = int(input())
lst = list(map(int, sys.stdin.readline().split()))
oper = list(map(int, sys.stdin.readline().split()))
oper_lst = []   # 0 +, 1 -, 2 *, 3 //


min = 0
max = 0
res = lst[0]
cnt_max = 0
cnt_min = 0
for i in range(math.factorial(n-1) // (math.factorial(oper[0]) * math.factorial(oper[1]) * math.factorial(oper[2]) * math.factorial(oper[3])))
    if len(oper_lst) == n - 1:
        res = lst[0]
        for j in range(n-1):
            if oper_lst[j] == 0:
                res += lst[j+1]
            elif oper_lst[j] == 1:
                res -= lst[j+1]
            elif oper_lst[j] == 2:
                res *= lst[j+1]
            elif oper_lst[j] == 3:
                if lst[j+1] == 0:
                    print('zero divide is impossble')
                    continue
                res //= lst[j+1]
            else:
                print('error occured')
        if res > max or cnt_max == 0:
            max = res
        elif res < min or cnt_min == 0:
            min = res

print(max)
print(min)