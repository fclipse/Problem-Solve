import sys
n = int(input())
lst_n = list(map(int, sys.stdin.readline().split()))
m = int(input())
lst_m = list(map(int, sys.stdin.readline().split()))

for i in lst_m:
    if i in lst_n:
        print(1)
    else:
        print(0)