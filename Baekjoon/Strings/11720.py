# 첫째줄의 숫자 개수(n)를, 다음 줄에 공백없이 숫자n개를 입력받고 그 합을 출력하는 프로그램
# 선언부
import sys

# 입력부
n = int(input())
num = list(map(int, input()))

# 연산출력부
#print(num)
print(sum(num))