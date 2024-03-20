# '얼른 마스크'씨 회사 전기자동차의 행복한 일련번호
def happy(n):
    sum = 0
    for i in str(n):
        sum += int(i) **2
    return sum

happy_lst = []
n = 1
while n < 10000:
    lst = [n]
    while True:
        lst.append(happy(lst[-1]))
        if lst[-1] == 1:
            happy_lst.append(n)
            break
        elif lst.count(lst[-1]) > 1:
            break
    n += 1
print(len(happy_lst) * sum(happy_lst))