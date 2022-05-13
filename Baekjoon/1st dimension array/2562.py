#1 ~9번째줄에 각각 1개씩 9개 자연수 입력, 최대값이 무엇이고 몇 번째 수인지 출력
import sys

arr = []
for i in range(9):
    arr.append(int(sys.stdin.readline()))
max = max(arr)
index = arr.index(max)

print(max)
print(index + 1)                # 실수주의, index 값과 몇 번째 값인지는 1차이남