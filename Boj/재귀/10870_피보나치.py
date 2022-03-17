# n번째의 피보나치 수를 출력하는 프로그램, n은 0부터 시작.
def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

n = int(input())
print(fibonacci(n))