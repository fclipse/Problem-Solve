# 칵테일을 마셨을 때 홀수 칵테일이 짝수 칵테일보다 맛있고
# 수가 높은 칵테일이 더 맛있다.
# 세 칵테일의 고유 번호가 주어질 때
# 가장 맛있는 칵테일 조합(수를 곱함)을 출력하는 문제.
a, b, c = map(int, input().split())
odd_res = 1
even_res = 1
cnt = 0
for i in [a, b, c]:
    if i % 2 == 1:
        odd_res *= i
        cnt += 1    # 다 111이면 res만으로는 구분 못함
    else:
        even_res *= i

if cnt == 0:
    print(even_res)
else:
    print(odd_res)