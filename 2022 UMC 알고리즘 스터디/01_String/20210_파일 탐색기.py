# 어렵...
import sys
mapping = dict(zip((), ''))
def convert(n, MAX):
    res = 0


n = int(input())
words = []
MAXLEN = 0
for _ in range(n):
    words.append(sys.stdin.readline().strip('\n'))
    if len(words[-1]) > MAXLEN:
        MAXLEN = len(words[-1])

for i in range(MAXLEN):
