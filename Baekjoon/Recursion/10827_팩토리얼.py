# 재귀함수로 팩토리얼 구현
def factorial(n):
    if n <= 1:
        return 1
    else:
        return n * factorial(n-1)

n = int(input())
print(factorial(n))