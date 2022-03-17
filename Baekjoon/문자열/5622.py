# 전화기 다이얼을 돌려 원하는 번호를 입력하는 시간 구하기

# 입력부
word = input()

# 연산부
sum = 0
dial = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
for i in word:
    for j in dial:
        if i in j:
            sum += dial.index(j) + 3

# 출력부
print(sum)