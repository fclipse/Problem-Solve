# 입력받은 수의 각 자리수를 내림차순으로 정렬해 출력하는 프로그램
n = input()
lst = []
for i in n:
    lst.append(int(i))

lst.sort(reverse = True)
lst = list(map(str, lst))
lst = ''.join(lst)
print(lst)


##
n = input()
lst = [_ for _ in n]
print(''.join(sorted(lst, reverse=True)))