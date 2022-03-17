# 알파벳, 숫자(0~9)가 주어졌을 때 주어진 글자의 아스키코드값을 출력하는 프로그램
import sys
input = input()             # .isalpha() -> 주어진 문자열이 알파벳으로만 구성되는지 판단
print(ord(input))           # ord() -> 문자 -> 아스키코드
                            # chr() -> 아스키코드 -> 문자