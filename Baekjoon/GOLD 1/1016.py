# 제곱 ㄴㄴ수
# min <= k <= max인 제곱ㄴㄴ수 k의 개수를 출력하는 프로그램
# k는 1보다 큰 제곱수로 나누어 떨어지지 않는다.
min, max = list(map(int, input().split()))
# 에라토스테네스의 체 응용 버전
arr = [1] * (max - min + 1)
k = 1
while k**2 < max:
    k += 1
    if min % k**2 == 0:
        arr[0] = 0
    # IDEA : min을 k**2으로 나눈 나머지를 k**2에서 뺀 만큼을 arr리스트의 인덱스에 넣어 제거하기를 반복하면 에라토스테네스의 체와 동일한 효과.
    # **인덱스 주의!!
    for i in range(k**2 - (min % k**2), max - min + 1, k**2):
        arr[i] = 0
cnt = 0
for i in arr:
    if i:
        cnt += 1
print(cnt)