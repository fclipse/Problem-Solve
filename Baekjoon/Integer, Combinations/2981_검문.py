# 집합 안의 수를 모두 나눴을 때, 그 나머지가 같은 수를 구하는 문제
# 수학적으로, x, y, z가 있을 때, 
# x = m*a + r
# y = m*b + r
# z = m*c + r이므로
# x-y = m(a-b)
# y-z = m(b-c) 이어서
# 항의 차들의 최대공약수의 약수들을 구해주면 된다.
# 주의할 점은 n = 2일때 두 수의 차가 한개만 나오므로 이상하다 싶어 두 수의 최대공약수를 구하지 말고, 이 차이를 바로 GCD로 정해 그 수의 약수를 구해야 한다.

import sys, math
def gcd(a, b):
    if b > a:
        a, b = b, a
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

n = int(input())
lst = []
diff = []
ans = []
for i in range(n):
    lst.append(int(sys.stdin.readline()))
lst.sort()
#print(lst)

for i in range(n-1):
    diff.append(lst[i+1]-lst[i])

if n > 2:
    GCD = gcd(diff[0], diff[1])
else:
    GCD = diff[0]   # 값이 두 개만 있을 때는 그냥 차 자체를 사용해야함. 두 수의 최대공약수가 아니라.
#print(diff)

for i in range(2, n-1):
    GCD = gcd(GCD, diff[i])

for i in range(2, int(GCD**0.5)+1): # 제곱근 포함 안 해줘서 틀림
    if GCD % i == 0:
        ans.append(i)
        if i != GCD//i:
            ans.append(GCD//i)
ans.sort()
ans.append(GCD)
print(' '.join(map(str, ans)))
#print(GCD, ans, diff)