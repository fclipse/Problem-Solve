n, m = map(int, input().split())
if n < m:
    n, m = m, n
if n % m == 0:
    print('win')
else:
    if 