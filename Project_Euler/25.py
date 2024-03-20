# 피보나치 수열에서 처음으로 1000자리가 되는 항을 찾는 알고리즘
def fibo(n):
    if n < 3:
        return 1
    elif fibonazzi[n] > 0:
        return fibonazzi[n]
    else:
        fibonazzi[n] = fibo(n - 1) + fibo(n - 2)
        return fibonazzi[n]

n = 1
pre_n = 1
fibonazzi = [0, 1, 1] + [0] * 100000
while True:
    if len(str(fibo(n))) == 1000:
        break
    elif n < 100000:
        n += 1
    else:
        print('not enough')
        break
print(n)