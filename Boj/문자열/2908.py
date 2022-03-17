# 0이 없는 두 세자리수를 뒤집어 대소비교하는 프로그램. 뒤집었을 때 큰 수 출력
# 입력부
a, b = input().split()
       # reversed -> 원래 변수는 그대로, 뒤집힌 reversed 객체 생성
       # 복잡해서 그냥 새 변수 사용.

# 연산부
x = ''
y = ''
for i in range(3):
    x += a[2-i]
    y += b[2-i]

# 출력부
print(max([int(x), int(y)]))