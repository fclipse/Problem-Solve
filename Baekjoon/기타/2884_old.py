import sys
h, m = map(int, sys.stdin.readline().split())

sum = h * 60 + m
sum -= 45

if sum < 0:
    sum += 24 * 60
hour = sum // 60
min = sum % 60

print(hour, min)