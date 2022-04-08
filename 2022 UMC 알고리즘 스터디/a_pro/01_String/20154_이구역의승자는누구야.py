# 입력받은 문자열을 주어진 코드표대로 숫자를 맵핑한 뒤
# 앞에서부터 두 개씩 더한 결과값을 기록하고,
# 결국 하나로 나온 숫자가 홀수/짝수인지에 따라 출력을 하는 프로그램
# 두 개씩 묶어 계산하는데, 계산 순서를 정할 때 어떤 자료구조가 좋을 지 고민이 되었음.
from collections import deque

s = input()
code = dict(zip([chr(i) for i in range(65, 91)], '32123333113133122212112221'))

lst = deque()
temp_lst = deque()
for i in s:
    lst.append(int(code[i]))

while len(lst) > 1:
    temp = lst.popleft() + lst.popleft()
    temp %= 10
    temp_lst.append(temp)
    if len(lst) <= 1:
        lst.extendleft(temp_lst)
        temp_lst.clear()

if lst[0] % 2 == 1:
    print("I'm a winner!")
else:
    print("You're the winner?")