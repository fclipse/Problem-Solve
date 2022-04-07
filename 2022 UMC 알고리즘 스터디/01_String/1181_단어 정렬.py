# 단어 정렬
# 길이순으로 정렬하되, 길이가 같다면 알파벳순으로 정렬하는 프로그램
# 처음 순서가 유지된다는 점을 이용, 알파벳 정렬을 먼저 하고 다음에 길이순 정렬을 했다.
import sys
n = int(input())
words = []
for i in range(n):
    words.append(sys.stdin.readline().strip('\n'))
words = list(set(words))    # 중복 제거

words.sort()                # 알파벳 순 정렬
words.sort(key=lambda words:len(words)) # 길이순 정렬
for i in words:
    print(i)