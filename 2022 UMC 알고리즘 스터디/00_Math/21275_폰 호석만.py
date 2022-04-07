a, b = input().split()
min_a = 2
min_b = 2
# 각 입력받은 수가 표현될 수 있는 최소 진법 계산, 숫자면 10진법
for i in a:
    if ord(i) >= 97:
        if ord(i) - ord('a') + 11 > min_a:
            min_a = ord(i) - ord('a') + 11  # n진법 -> 0~n-1로 구성.
    else:
        if int(i) > min_a:
            min_a = int(i) + 1
for i in b:
    if ord(i) >= 97:
        if ord(i) - ord('a') + 11 > min_b:
            min_b = ord(i) - ord('a') + 11
    else:
        if int(i) > min_b:
            min_b = int(i) + 1
# A부터 10진법으로 변환
# A가 가능한 수들 모아놓은 리스트
lst_a = []
# A가 가능한 수들 리스트에 대응하는, 몇진법이 되는지 모아놓은 리스트
num_a = []
i = min_a
while i <= 36:
    A = 0
    length = len(a)
    for index, word in enumerate(a):
        if ord(word) >= 97:
            A += i ** (length - index - 1) * (ord(word) - ord('a') + 10)    # n진법에서 n-1까지 표현됨.
        else:
            A += i ** (length - index - 1) * (int(word))
    lst_a.append(A)
    num_a.append(i)
    i += 1

lst_b = []
num_b = []
i = min_b
while i <= 36:
    B = 0
    length = len(b)
    for index, word in enumerate(b):
        if ord(word) >= 97:
            B += i ** (length - index - 1) * (ord(word) - ord('a') + 10)
        else:
            B += i ** (length - index - 1) * (int(word))
    lst_b.append(B)
    num_b.append(i)
    i += 1

cnt = 0
i_a = 0
i_b = 0
for i , num in enumerate(lst_a):
    if num in lst_b:
        cnt += 1
        i_a = i
        i_b = lst_b.index(num)

if cnt > 1:
    print('Multiple')
elif cnt == 1 and num_a[i_a] != num_b[i_b]:
    print(lst_a[i_a], num_a[i_a], num_b[i_b])
else:
    print('Impossible')

#print(lst_a)
#print(num_a)
#print(lst_b)
#print(num_b)