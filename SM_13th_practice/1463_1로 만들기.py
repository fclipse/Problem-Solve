# x = 3**a + 2**b + c 일때, a + b + c의최솟값을 구하는 문제
x = int(input())
n = 0
while x >= 3 **n:
    n += 1
a = 0
b = 0
c = 0
min = -1
for a in range(n):  # 0부터 n-1까지 반복
    b = 0
    while x > 3**a * 2**b:
        b += 1
    if x < 3**a * 2**b:
        b -= 1
    c = x - 3**a * 2**b
    if a + b + c < min or min == -1:
        min = a + b + c
    print(a, b, c)

print(min)