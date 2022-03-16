#No.18 삼각형을 따라 내려가면서 합이 최대가 되는 경로 찾기
import math
import itertools as it

def c(n, r):
    res = math.factorial(n) / (math.factorial(r) * math.factorial(n-r))
    return int(res)

# ** 5개시도 -> 본게임으로
arr = []
#arr 입력
for i in range(18):
    arr.append(input().split(' '))
#arr 정규화
for i in range(18):
    arr[i] = list(map(int, arr[i]))

length = len(arr)                                               #arr 길이 저장
cnt = 0
max = 0
best_solution = []
#모든 경로 계산
solution = []
for i in range(length):                                         #경로별 반복
    case = list(it.combinations(range(length - 1), i))          #가능한 combination 계산
    num = len(case)                                             #경로당 경우의 수
    for j in range(num):                                        #경우의 수 당 반복
        coordinate = [0, 0]
        solution = [0] * (length - 1)                           #solution 초기화
        sum = arr[0][0]                                         #sum, 좌표 초기화
        #print('sum0 :', sum)
        for k in range(i):                                      #solution 만들기
            solution[case[j][k]] = 1
        #print(case[j])
        for k in range(length - 1):                                     
            coordinate[1] += solution[k]                        #좌표 더하기
            coordinate[0] += 1
            sum += arr[coordinate[0]][coordinate[1]]
            #print(coordinate)
            #print(arr[coordinate[0]][coordinate[1]])
        if sum > max:                                           #합 최댓값 산출
            max = sum
            best_solution = solution
        cnt += 1
        #print(solution, sum)

#출력
print('trial :', cnt)
print('max :', max)
print('best solution', best_solution)
print('count :', cnt)