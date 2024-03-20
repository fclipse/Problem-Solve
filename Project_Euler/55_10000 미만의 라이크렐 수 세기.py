def palidrome(k):       # 대칭수 찾는 함수, O(logn)
    k = str(k)
    length = len(k)
    for i in range(length//2):
        if k[i] != k[length - i - 1]:
            return 0
    return 1

n = 1
lychrel = 0         # 라이크렐 수의 개수
while n <= 10000:   # 10000까지 반복
    cnt = 0         # 대칭수 되는지 체크
    standard_n = n  # 더하는 두 n 중 첫번째 n, 대칭되는 n은 reversed_n
    for i in range(50):
        reversed_n = int(''.join(reversed(str(standard_n))))
        sum_n = standard_n + reversed_n
        if palidrome(sum_n):
            cnt += 1    # 대칭수가 된다면 break
            #print(sum_n)
            break
        else:
            standard_n = sum_n
    if cnt == 0:    # 50번동안 대칭수가 하나도 없다면
        lychrel += 1
    n += 1
print(lychrel)
    