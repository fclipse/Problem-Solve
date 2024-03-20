# 입력받은 문자열에서 크로아티아 알파벳의 개수를 세는 프로그램
# 입력부
word = input()

# 연산부
alphabet = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
jump = 0
cnt = 0
for i in range(len(word)):
    if jump > 0:
        jump -= 1
        continue
    if i < len(word) - 2:
        if word[i:i+3] in alphabet:
            jump += 2
    if i < len(word) - 1 :
        if word[i:i+2] in alphabet:
            jump += 1
    cnt += 1
    #print(cnt, i)

# 출력부
print(cnt)