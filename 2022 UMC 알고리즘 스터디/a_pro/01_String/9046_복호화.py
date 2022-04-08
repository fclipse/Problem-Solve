# 주어진 문자열에서 가장 많은 단어가 무엇인지 출력하는 프로그램
# 여러 개 있다면 ? 출력
import sys
t = int(input())
for _ in range(t):
    words = sys.stdin.readline().strip('\n')
    max = 0
    MSW = '?'   # most significant word
    for i in words:
        if i == ' ':    # 문자가 공백일 경우는 제외
            continue
        if words.count(i) > max and i != MSW:   # 현 단어가 제일 많을 경우 갱신
            MSW = i
            max = words.count(i)    
        elif words.count(i) == max and i != MSW:    # 숫자는 같은데 다른거면 ?으로 설정
            MSW = '?'
    print(MSW)  # 가장 마지막에 설정된 MSW으로 출력