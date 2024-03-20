# 설탕 Nkg을 5kg과 3kg 봉지로 최소 몇 개로 배달할 수 있는지 출력하는 프로그램
# 먼저 5로 최대한 뺀 다음 3으로 나누어지는지 계싼.
# 안된다면 5 개수를 1씩 줄여가며 0이 될 때까지 나머지가 3으로 나누어지는지  계산
# 5 개수가 n//5부터 0일때까지 다 안된다면 -1 출력
 
# 입력부
n = int(input())

# 연산부
success = 0
answer = 0
p = n % 5                  # p : n 5로 나눈 나머지
                            # i : 3개수
for i in range(n // 5 + 1):     #0부터 n//5까지 반복
    if (p + i * 5) % 3 == 0 :
        success = 1
        answer = (n // 5 - i) + (p + i * 5) // 3
        break

# 출력부
if success == 1:
    print(answer)
else:
    print(-1)