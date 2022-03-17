# DP로 푸는 피보나치
# 재귀호출 시 fibonazzi(0)과 fibonazzi(1)이 얼마나 호출되었는지 출력하는 문제
# fibo(0)은 fibo(2)에서만 호출되므로 그 횟수가 같다는 점이 인상적임.
# fibo(2)까지만 fibo(n-1), fibo(n-2)를 += 1해주고 그 밑은 따로 처리
# n < 2일때 케이스도 따로 처리
# 하향식 문제 풀이 사용

t = int(input())
for i in range(t):
    n = int(input())
    lst = [0] * (n+2)
    lst[n] = 1
    if n > 1:
        for j in range(n, 1, -1):
            lst[j-1] += lst[j]
            lst[j-2] += lst[j]
        lst[0] = lst[2]
    print(lst[0], lst[1])