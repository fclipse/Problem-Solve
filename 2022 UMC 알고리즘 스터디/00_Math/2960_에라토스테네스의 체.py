# 에라토스테네스의 체에서 k 번째 지워지는 숫자를 출력해내는 프로그램
# 직접 구현해서 cnt로 값을 세는 알고리즘
# 0331
n, k = map(int, input().split())
lst = [0] * (n + 1)
cnt = 0
res = 0
i = 2
while i <= n and cnt < k:
    j = i
    if lst[i] == 0:
        while j <= n and cnt < k:
            if lst[j] == 0:
                lst[j] = 1
                cnt += 1
                res = j
            j += i
    i += 1
print(res)