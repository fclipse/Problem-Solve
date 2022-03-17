# 알파벳 단어에서 가장 많이 사용된 알파벳을 출력하는 프로그램
# 대소문자 구분 x, 출력은 대문자
# 가장 많이 사용된 알파벳이 여러개면 ? 출력

# 입력부
word = input()

# 출력연산부
cnt = [0] * 26
# 각 알파벳을 중복되지 않은 리스트로 재구성
for i in range(26):
    if chr(i+65) in word or chr(i+97) in word :
        cnt[i] += word.count(chr(i+65)) + word.count(chr(i+97))

# 출력부
#print(cnt)
if cnt.count(max(cnt)) >= 2:
    print('?')
else:
    print(chr(cnt.index(max(cnt)) + 65))