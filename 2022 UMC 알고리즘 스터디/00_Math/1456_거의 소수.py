# 어떤 수가 소수의 n제곱일때 그 수를 거의 소수라고 한다.
# a 이상 b 이하의 거의 소수가 몇 개인지를 찾는 프로그램
# 소수 리스트를 만들어(b의 제곱근 이하까지) 각 소수마다 k제곱을 해서
# 범위 안에 있으면 개수를 카운팅한다.
a, b = map(int, input().split())
MAX = int(b**0.5)
check = [0] * (MAX + 1)
prime_lst = set()
cnt = 0

# 소수 리스트 만들어줌
i = 2
while i <= MAX:
    if check[i] == 0:
        prime_lst.add(i)
        j = i
        while j <= MAX:
            check[j] = 1
            j += i
    i += 1

for i in prime_lst:
    k = 2    
    while i ** k <= b:
        if i **k >= a:
            cnt += 1
        k += 1
print(cnt)