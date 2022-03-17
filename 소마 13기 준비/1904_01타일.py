n = int(input())
lst = [1, 2, 0]
for i in range(2, n):
    lst[2] = (lst[1] + lst[0]) % 15746
    lst[0], lst[1] = lst[1], lst[2]
if n < 3:
    print(lst[n-1])
else:
    print(lst[-1])