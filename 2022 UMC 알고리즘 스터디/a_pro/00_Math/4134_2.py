# 에라토스테네스 메모리 초과 떠서 그냥 소수판정함수 만들어서 했는데 성공함.
# 소수판정함수에서 2부터 n**0.5(이하 정수)까지만 나눠줘도 됨. 약수 대칭임.
# 0, 1은 예외적으로 소수가 아님을 처리해줘야함.
# n 이상 최소 소수를 출력하는 프로그램.
import sys
def prime(n):
    if n < 2:
        return 0
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return 0
    return 1

t = int(input())
for _ in range(t):
    n = int(sys.stdin.readline())
    i = n
    while prime(i) == 0:
        i += 1
    print(i)