# 한 단어 내에서 알파벳 a-z가 있다면 그 인덱스를, 없다면 -1을 출력하는 프로그램
import sys

# 입력부
word = input()

# 연산출력부
for i in range(97, 123):
    if chr(i) in word:
        print(word.index(chr(i)), end = ' ')
    else :
        print(-1, end = ' ')