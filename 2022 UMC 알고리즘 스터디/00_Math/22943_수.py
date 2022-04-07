# 0-9까지 k개의 수를 조합해 만들 수 있는 수들 중
# 조건 1과 조건 2에 부합하는 숫자가 몇 개 있는지 출력하는 프로그램
# 조건 1 : 서로 다른 두 개의 소수의 합으로 나타낼 수 있는 경우
# 조건 2: m으로 나누어떨어지지 않을 때까지 나눈 수가 두 소수의 곱인 경우(중복 가능)
# 1. 소수를 계속 이용해야 해서 처음에 에라토스테네스로 리스트 만듦, 범위는 k에따라 정해짐
# 2. set자료형을 이용해 접근시 시간복잡도를 줄임(set는 in 연산 시간복잡도가 O(1))
# 3. 2조건이 더 많은 수들을 걸러낼 수 있다고 생각해(m으로 나눠서 일단 수 크기를 줄여줌) 2조건을 쓰고 1조건을 씀
# 4. 1조건 구현 시 수의 절반 미만까지만 반복을 시켜 중복을 배제함.
# time 모듈 사용시 대략 1초 정도 걸림
# 난이도 7/10, 4/5 해결
from itertools import permutations
k, m = map(int, input().split())
lst = []
MAX = 98765 // 10**(5-k)    # K개의 숫자를 고를 때 나올 수 있는 가장 큰 수

# 일단 최대 범위까지 소수 리스트 만들어 놓음
check = [0] * (MAX + 1)
prime_lst = set()   # 있는지 체크하기에는 set 자료형이 최고
for i in range(2, MAX+1):
    if check[i] == 0:
        check[i] = 1
        prime_lst.add(i)  # 1부터 N까지 소수 리스트
        j = 1
        while i * j <= MAX:
            check[i*j] = 1
            j+=1

# k개의 숫자 조합
for num in permutations(range(10), k):
    if num[0] == 0: # 첫 자리가 0이면 취급 안함
        continue
    N = int(''.join(list(map(str, num))))   # 숫자 조합
    temp = N
    while temp % m == 0:    # m으로 나누어떨어지지 않을 때까지 나눠줌
        temp //= m
    i = 2
    temp_lst = []
    while i <= int(temp**0.5):  
        if temp % i == 0:   # 한 번이라도 소수와 소수가 아닌 수가 있어도 반례이므로 break 해줌
            if i in prime_lst and temp//i in prime_lst: # 2조건
                j = 2
                while j < N // 2:  # 1조건
                    if j in prime_lst and N-j in prime_lst:
                        lst.append(N)
                        break
                    j += 1
            break   #?
        i += 1
                    
print(len(lst))