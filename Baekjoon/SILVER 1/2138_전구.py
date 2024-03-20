n = int(input())
start = list(map(int, list(input())))
end = list(map(int, list(input())))

print(start)
print(end)
def change(n, lst):     # 인덱스와 리스트가 들어왔을 때, 그 인덱스를 바꾼 리스트를 반환하는 함수
    if n == 0:
        lst[0] = 1 - lst[0]
        lst[1] = 1 - lst[1]
    elif n == len(lst)-1:
        lst[-1] = 1 - lst[-1]
        lst[-2] = 1 - lst[-2]
    else:
        lst[i-1] = 1 - lst[i-1]
        lst[i] = 1 - lst[i]
        lst[i+1] = 1 - lst[i+1]
    return lst

def points(lst1, lst2): # 유사도를 반환하는 함수
    length = len(lst1)
    point = 0
    for i in range(length):
        if lst1[i] == lst2[i]:
            point += 1
    return point

max = 0
if_end = 1
max_i = 0
cnt = 0
while if_end:
    i = 0
    if_end = 0
    while i < len(start):
        temp = change(i, start)
        temp_point = points(temp, end)
        if temp_point > max:
            if_end = 1
            max_i = i
            max = temp_point
        i += 1
    if if_end:
        cnt += 1
        start = change(max_i, start)
    print(start, max_i)
print(start, 'cnt', cnt)