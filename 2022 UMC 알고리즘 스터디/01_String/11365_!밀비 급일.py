# 문자열을 입력받고, 뒤집어서 출력하는 프로그램
import sys
while True:
    word = sys.stdin.readline().strip('\n')
    if word == 'END':
        break
    print(''.join(list(reversed(word))))