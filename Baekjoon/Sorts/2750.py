# 정렬하는 프로그램
# 퀵정렬 이용
import sys

def quicksort(lst):
    length = len(lst)
    if length <= 1:
        return lst
    
    mid = lst[length//2]
    lst.remove(mid)
    left = []
    right = []

    for i in lst:
        if i > mid:
            right.append(i)
        else:
            left.append(i)
    
    return quicksort(left) + [mid] + quicksort(right)

n = int(input())
lst = []
for i in range(n):
    lst.append(int(sys.stdin.readline().strip('\n')))

lst = quicksort(lst)
for i in lst:
    print(i)