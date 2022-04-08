# n개 줄에 문자열을 입력받아 각 문자열의 확장자만 개수를 세서
# 사전순으로 정렬한 뒤 각각의 이름과 개수를 출력하는 프로그램
import sys
n = int(input())
files = dict()
for _ in range(n):
    word = sys.stdin.readline().strip('\n').split('.')
    if word[1] in files:
        files[word[1]] += 1
    else:
        files[word[1]] = 1

files_lst = sorted(list(files.keys()))
for i in files_lst:
    print(i, files[i])