import sys
n = int(sys.stdin.readline())
lst = []
for i in range(n):
    lst.append(int(sys.stdin.readline()))

sorted_lst = []
length = len(lst)
sum = 0

counting_sort = [0] * 8001
max_num = []
max = 0 # 빈도
# 카운팅 정렬
for i in lst:
    counting_sort[i + 4000] += 1

# 최빈값 찾기, 여러개면 max_num에 추가
for i in range(8001):
    if counting_sort[i]:
        if counting_sort[i] > max:
            #print('new', i - 4000)
            max = counting_sort[i]
            max_num = []
            max_num.append(i - 4000)
        elif counting_sort[i] == max:
            #print('added', i - 4000)
            max_num.append(i - 4000)
        # 카운팅 정렬 부분
        for j in range(counting_sort[i]):
            sorted_lst.append(i - 4000)
            sum += i - 4000

ave = round(sum / length)
mid = sorted_lst[length//2]
range = sorted_lst[length - 1] - sorted_lst[0]
#print(sorted_lst)
#print(max_num)

print(ave)
print(mid)
if len(max_num) == 1:
    print(max_num[0])
else:
    max_num.sort()
    print(max_num[1])
print(range)