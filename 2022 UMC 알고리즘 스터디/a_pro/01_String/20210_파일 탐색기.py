# 어렵...
import sys
from collections import deque
mapping = dict(zip((), ''))
def convert(n, MAX):
    res = []
    n = deque(n)
    temp = ''
    length = len(n)
    for i in range(length):
        if ord('a') <= ord(n[0]) <= ord('z') or ord('A') <= ord(n[0]) <= ord('Z'):
            if temp:
                res.append(temp)
                temp = ''
            res.append(n.popleft())
        else:
            temp += n.popleft()
    return res

n = int(input())
words = []
sort_lst = [[] * (52 + 10)]
sort_lst_save = [[] * (52 + 10)]
MAXLEN = 0
for _ in range(n):
    words.append(sys.stdin.readline().strip('\n'))
    if len(words[-1]) > MAXLEN:
        MAXLEN = len(words[-1])

for i in range(len(words)):
    words[i] = convert(words[i], MAXLEN)
for i in words:
    print(i)