# 20000 이하의 수 n을 받아 그 수의 팩토리얼에서 0이 아닌 가장 낮을 자리를 
# 출력하는 문제
import math
n = int(input())
for i in reversed(str(math.factorial(n))):
    if i != '0':
        print(i)
        break