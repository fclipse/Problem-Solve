# 1463 DP 풀이
x = int(input())
lst = [0] * (x+1)

for i in range(2, x+1):
    lst[i] = lst[i-1] + 1
    if i % 2 == 0:
        lst[i] = min(lst[i//2]+1, lst[i])
    if i % 3 == 0:
        lst[i] = min(lst[i//3]+1, lst[i])

print(lst[x])