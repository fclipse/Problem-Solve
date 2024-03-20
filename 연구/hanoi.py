import time, sys
sys.setrecursionlimit(10**8)


st = time.time()

def hanoi(n):
    sum = 1
    for i in range(n-1):
        sum = sum * 2 + 1
    return sum


def hanoi_recursive(n):
    if n == 1:
        return 1
    return hanoi_recursive(n-1)*2+1

#hanoi(100000)
hanoi_recursive(100000)
print(time.time() - st)