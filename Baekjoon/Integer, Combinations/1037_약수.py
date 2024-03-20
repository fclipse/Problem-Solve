# 1과 n을 제외한 n의 약수가 모두 주어질 때 n을 출력하는 문제
n = int(input())
lst = sorted(list(map(int, input().split())))
print(lst[0] * lst[-1])