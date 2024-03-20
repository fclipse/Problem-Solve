# 분수 격자에서 X번째 분수가 무엇인지 찾는 문제
# IDEA : 좌표, x + y = k, n까지 합공식 -> 2292와 비슷.

# 입력부
x = int(input())

# 연산부
i = 1
while 0.5 * (i + 1) * i < x:
    i += 1

# k 짝수(홀수번째 줄) -> 오른쪽 위로 진행 
coordinate = [0, 0]
u = x - 0.5 * (i-1) * i     # 나머지

if i % 2 == 0:
    coordinate = [u, i + 1 - u]
else:
    coordinate = [i + 1 - u, u]
coordinate = list(map(int, coordinate))

# 출력부
print(coordinate[0], '/', coordinate[1], sep = '')