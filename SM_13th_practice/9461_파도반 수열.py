# 9461 파도반 수열, dp같은 방법으로 풀이 가능.
# 나선을 따라 가며 
t = int(input())
for i in range(t):
    n = int(input())
    lst = [1, 1, 1, 2, 2]
    if n < 5:
        print(lst[n-1])
    else:
        for i in range(5, n):
            lst.append(lst[i-1] + lst[i-5])
        print(lst[n-1])