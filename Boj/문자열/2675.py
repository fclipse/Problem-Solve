# 문자열 t개를 입력받아 각각 r번만큼 각 문자열의 문자를 반복해 출력하는 문제

import sys
# 입력부
n = int(input())
repeat = []
word = []
for i in range(n):
    input = sys.stdin.readline().split()    # .split()만 넣어줘도 개행문자 사라짐
    #print(input)
    repeat.append(int(input[0]))
    word.append(input[1])

# 출력부
for i in range(n):
    for j in word[i]:
        for k in range(repeat[i]):
            print(j, end = '')
    print('')