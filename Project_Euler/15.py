#No.15 20*20 격자에서 한 모서리 끝에서 다른 모서리 끝으로 가는 경우의 수
#일반화해서 n*n 격자에서 가능한 경우의 수 구하는 프로그램 만듦 
arr = []
n = int(input('격자 크기 입력 :'))
for i in range(n+1):
    arr.append([])
    for j in range(n+1):
        arr[i].append([])

#수 입력
for i in range(n+1):
    arr[0][i] = 1
    arr[i][0] = 1

for i in range(n+1):
    for j in range(n+1):
        if arr[i][j] == []:
            arr[i][j] = arr[i-1][j] + arr[i][j-1]


#배열 출력
#for i in range(n+1):
#    print(arr[i])

print('All possible ways :', arr[n][n])