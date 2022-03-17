# 문자열에서 단어의 개수를 세는 프로그램
# 입력부
string = input()
#print(string)

# 연산출력부

if string :                         # 문자열 없는 경우 대비
    while string[0] == ' ':         # 문자열 앞, 뒤 공백 제거
        string = string[1:]
        if not string:              # 전부 공백인 경우 대비, string[0]에서 오류남
            break
if string:
    while string[-1] == ' ':
        string = string[:-1]
if string :
    n = string.count(' ')
    print(n+1)
else :
    print(0)