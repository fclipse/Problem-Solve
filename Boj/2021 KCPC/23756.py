#23756 2021 고려대 경시대회 1번
#노브 각도 배열 최소각으로 돌리는 각도합
n = int(input())
arr = []
sum = 0
a0 = int(input())
for i in range(n):
    arr.append(int(input()))
    if abs(arr[-1] - a0) > 180:      #왼쪽으로
        sum += 360 - abs(arr[-1] - a0)
    else :                      #오른쪽으로
        sum += abs(arr[-1] - a0)
    a0 = arr[-1]
print(sum)