# ord('A') = 65, ord('1') = 49
n, b = input().split()
b = int(b)
res = 0
for i in range(len(n)):
    if ord(n[i]) > 64:
        res += (ord(n[i]) - 55) * b **(len(n) - 1 - i)
    else:
        res += int(n[i]) * b ** (len(n) - 1 - i)
print(res)