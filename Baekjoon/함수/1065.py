# 한수 : X의 각 자리가 등차수열을 이루는 수
# N보다 작거나 같은 한수이 개수를 출력하는 프로그램
# 한수면 1, 아니면0을 반환하는 함수
def han(n):
    length = len(str(n))
    n = list(map(int, str(n)))
    # 길이 2 이하는 그냥 반환.
    if length <= 2 :
        return 1
    
    for i in range(length - 2):
        if n[i + 1] - n[i] != n[i + 2] - n[i + 1] :
            return 0
    return 1

# 입력부
n = int(input())

# 연산부
cnt = 0
for i in range(1, n + 1) :
    if han(i) == 1:
        cnt += 1
print(cnt)