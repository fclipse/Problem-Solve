# 진짜 간단하게 짠 코든데 시간초과남..
# python으로 돌렸는데 이게 되네..?
import sys
s = sys.stdin.readline().strip('\n')
p = sys.stdin.readline().strip('\n')
if p in s:
    print(1)
else:
    print(0)