# a, b, c곱에 0부터 9까지 각 숫자가 얼마나 쓰였는지 찾는 알고리즘
import sys

numbers = []
for i in range(3):
    numbers.append(int(sys.stdin.readline()))

n = str(numbers[0] * numbers[1] * numbers[2])

for i in range(10):
    print(n.count(str(i)))