# 입력받은 문자열 중 그룹 단어(각 문자가 연속하는 단어)의 개수를 세는 문제

# 판별 함수선언
def group(w):
    #print(w)
    for i in range(len(w)):             # len(w)은 iterable하지 않음
        if i < len(w) - 1:
            if w[i] != w[i+1]:          #IlovePython
                # 문자열이 끝났는데, 그 뒤에 단어가 포함되어 있으면 안됨. 
                if w[i+1] in w[:i]:
                    return 0
    return 1        
# 입력부
n = int(input())
cnt = 0
for i in range(n):
    word = input()
    if group(word) == 1:
        cnt += 1

# 출력부
print(cnt)