# 11726 2*n 타일링
n = int(input())
lst = [0] * n
lst[0] = 1
if n > 1:
    lst[1] = 2
for i in range(2, n):
    lst[i] = lst[i-1] + lst[i-2]
print(lst[-1] % 10007)