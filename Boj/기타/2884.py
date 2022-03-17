import sys
h, m = map(int, sys.stdin.readline().split())
if m < 45:
    m = 60 - (45 - m)
    if h == 0:
        h = 23
    else :
        h -= 1
else : 
    m -= 45
print(h, m)