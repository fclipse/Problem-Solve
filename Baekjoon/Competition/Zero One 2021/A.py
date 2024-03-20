import sys, math
h, w, n, m = map(int, sys.stdin.readline().split())
print(math.ceil(h / (n+1)) * math.ceil(w / (m + 1)))o