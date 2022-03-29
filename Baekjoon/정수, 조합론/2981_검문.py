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
minimum = 1000000000
maximum = 1
for i in range(n):
    lst.append(int(sys.stdin.readline()))
    if lst[-1] > maximum:
        maximum = lst[-1]
    if lst[-1] < minimum:
        minimum = lst[-1]

ans = []
for i in range(n):
    lst[i] -= minimum
lst.sort()

for i in range(1, n-1):
    GCD = gcd(lst[i], lst[i+1])

for i in range(1, int(math.sqrt(GCD)+1)):
    if GCD % i == 0:
        ans.append(i)
        if i != GCD//i:
            ans.append(GCD//i)
ans.sort()
if 1 in ans:
    ans.remove(1)
print(' '.join(map(str, ans)))
print(ans, lst, GCD)