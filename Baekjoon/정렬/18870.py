# 좌표 압축
import sys
n = int(sys.stdin.readline())
x = list(map(int, sys.stdin.readline().split()))

compressed_x = list(map(str, sorted(list(set(x)))))
dict_x = dict.fromkeys(compressed_x)
for i in range(len(compressed_x)):
    dict_x[compressed_x[i]] = i
for i in x:
    print(dict_x[str(i)], end = ' ')