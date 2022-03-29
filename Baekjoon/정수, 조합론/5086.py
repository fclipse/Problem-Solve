# 두 수를 입력받아 첫째 수가 둘째 수의 약수 혹은 배수 관계인지 출력하는 프로그램
import sys
while True:
    a, b = map(int, sys.stdin.readline().split())
    if a == 0 and b == 0:
        break
    if b % a == 0:
        print('factor')
    elif a % b == 0:
        print('multiple')
    else:
        print('neither')