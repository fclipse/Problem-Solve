# m 이상 n 이하 소수 모두 출력하는 프로그램
m, n = list(map(int, input().split()))

num = 1
arr = [1] * 1000000 # 1부터 백만까지의 리스트
arr[0] = 0  #1은 안됨 처리

for i in range(2, 1001):
    if arr[i-1]:
        for j in range(2*i, 1000001, i):
            arr[j-1] = 0

for i in range(m, n+1):
    if arr[i-1]:
        print(i)