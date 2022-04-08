# 가로로 입력받은 5개의 문자들을 세로로 읽은 결과를 출력하는 프로그램
import sys
word = []
max = 0
for i in range(5):
    word.append(sys.stdin.readline().strip('\n'))
    if len(word[-1]) > max:
        max = len(word[-1])
lst = []
for i in range(max):
    for j in range(5):
        if len(word[j]) > i:
            lst.append(word[j][i])
print(''.join(lst))