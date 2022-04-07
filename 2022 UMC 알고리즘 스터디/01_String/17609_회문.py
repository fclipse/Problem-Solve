# 시간초과, 다시
import sys
t = int(input())
for _ in range(t):
    word = sys.stdin.readline().strip('\n')
    if word == word[::-1]:
        print(0)
    else:
        succeed = 0
        temp = word[:len(word)-1]
        if temp == temp[::-1]:
            succeed = 1
        else:
            for i in range(len(word)-1):
                temp = word[:i] + word[i+1:]
                if temp == temp[::-1]:
                    succeed = 1
                    break
        if succeed:
            print(1)
        else:
            print(2)