# 분해합 : N과 N을 이루는 각 자리수의 합. 
# g(n) = m일때 N은 M의 생성자이다.
def g(n):
    N = str(n)
    sum = n
    for i in N:
        sum += int(i)
    return sum

# N을 입력받았을 때, Brute Force로 N의 생성자를 구하는 함수
def disassemble(n):
    for i in range(1, n+1):
        if g(i) == n:
            return i
    return -1

n = int(input())
sol = disassemble(n)
if sol > 0:
    print(sol)
else:
    print(0)