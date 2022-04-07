# 수열이 주어졌을 때, 그 수열에서 소수인 수들의 최소공배수를 구하는 프로그램
# 수열에 같은 소수가 두 개 이상 존재할 가능성 고려
# 에라토스테네스 응용해서도 가능?
def prime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return 0
    return 1

length = int(input())
lst = list(map(int, input().split()))

res = 1
for i in lst:
    if prime(i) and res % i != 0:   # 같은 수가 여러번 나올 가능성 고려
        res *= i

if res > 1:
    print(res)
else:
    print(-1)