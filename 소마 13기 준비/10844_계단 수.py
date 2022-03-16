# 10844, 계단 수
# 길이가 n인 계단 수가 몇 개 있는지 구하는 문제
# 계단 수란 모든 인접한 자리의 차이가 1인 수
# dp문제, 삼각형 최소합 구하는 문제와 비슷한 느낌.
import copy
n = int(input())
res = [0] + [1] * 9
p_res = []
for i in range(n-1):
    p_res = copy.copy(res)
    res = [0] * 10
    for j in range(10):
        if j > 0:
            res[j] += p_res[j-1]
        if j < 9:
            res[j] += p_res[j+1]
print(sum(res) % 1000000000)