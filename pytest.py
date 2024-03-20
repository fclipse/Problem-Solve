def sol1(n):
    cnt = 0
    length = len(str(n))
    for i in range(length):
        if(i != length - 1):
            cnt += (n // 10**(i+1) - 1) * (10 ** i) + n % (10**i) + 1
    return cnt

def sol2(n):
    cnt = 0
    for i in range(1, n+1):
        strnum = str(i)
        for j in strnum:
            if int(j) == 0:
                cnt += 1
    return cnt


n = 1
cnt = 1
tmp1 = 0
tmp2 = 0

n = int(input())
print(sol1(n))
print(sol2(n))