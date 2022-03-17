# 고정비용, 가변비용, 가격을 입력받아 최초로 이익이 발생하는 손익분기점까지의 판매량을 출력하는 프로그램
# 선언부
import sys

# 입력부
a, b, c = list(map(int, sys.stdin.readline().split()))

# 출력부
sol = 0
if b >= c:
    print(-1)
else:
    sol = a//(c-b)
    print(sol + 1)