# 입력받은 문자열에서 숫자를 제거한 뒤
# 그 문자열 안에 찾고자 하는 문자가 연속된 형태로 들어 있는지를 확인해
# 출력하는 프로그램
import sys
word = sys.stdin.readline().strip('\n')
find = sys.stdin.readline().strip('\n')

numbers = set('0123456789')
parsed_word = []
for i in word:
    if i in numbers:
        continue
    parsed_word.append(i)
parsed_word = ''.join(parsed_word)

if find in parsed_word:
    print(1)
else:
    print(0)