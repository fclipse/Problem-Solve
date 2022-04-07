# 입력한 비밀번호가 조건을 만족하는지 검사하는 프로그램
# 1. 모음이 적어도 1개 이상 있어야 함
# 2. 모음 또는 자음이 3개 연속이면 안됨.
# 3. 같은 글자가 2개 이상 반복되면 안됨, ee oo는 제외.
import sys
aeiou = set(['a', 'e', 'i', 'o', 'u'])
def is_aeiou(k):
    if k in aeiou:
        return 1
    else:
        return 0

while True:
    word = sys.stdin.readline().strip('\n')
    if word == 'end':
        break
    if word.count('a') + word.count('e') + word.count('i') + word.count('o') + word.count('u') == 0:
        print('<%s> is not acceptable.' % word)
        continue
    succeed = 1
    if len(word) > 1:   # 밑에 2와 3을 같이 검사, 근데 3의 부족한 검사 횟수 1번을 미리 여기서 채움.
        if word[0] == word[1] and word[0] != 'e' and word [0] != 'o':
            print('<%s> is not acceptable.' % word)
            continue
    for i in range(len(word)-2):
        if is_aeiou(word[i]) == is_aeiou(word[i+1]) and is_aeiou(word[i+1]) == is_aeiou(word[i+2]):
            succeed = 0
            break
        if word[i+1] == word[i+2] and word[i+1] != 'e' and word[i+1] != 'o':
            succeed = 0
            break
    if succeed == 0:
        print('<%s> is not acceptable.' % word)
        continue
    print('<%s> is acceptable.' % word)