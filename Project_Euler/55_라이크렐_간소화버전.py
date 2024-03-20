def lychrel(n):
    for i in range(50):
        n += int(str(n)[::-1])
        if str(n) == str(n)[::-1]:
            return 0
    return 1

cnt = 0
for _ in range(10000):
    if lychrel(_+1):
        cnt += 1
print(cnt)