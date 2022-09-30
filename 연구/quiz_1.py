def nums(n):
    return int(10**(n-1) * 9 * n)

goal = int(input()) # 목표 자리 번수
length = 1  # 목표 자리 번수가 있는 자릿수 저장하는 변수
sum = 0     # 임시 변수, 목표까지 남은 거리 또는 이제까지 온 거리를 저장.
while True:
    if sum + nums(length) > goal:
        break
    sum += nums(length)
    length += 1  # 자릿수

goal -= sum # 목표까지 몇 자리 남았는지 저장
if goal != 0:
    sum = goal // length - 1
else:
    sum = 0

goal %= length   # 여전히 몇 자리 남았는지 저장
last_num = 10 ** (length-1) + sum
ans = str(last_num)[goal]
print(ans, last_num, goal)
