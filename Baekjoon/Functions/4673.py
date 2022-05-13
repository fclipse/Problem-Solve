# 10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램

# 생성자 함수, d(i) >= i 라는 특성 이용가능
def d(n):
    length = len(str(n))
    return n + sum(list(map(int, str(n))))

# 연산부
arr = []
for i in range(1, 10001):
    if not(d(i) in arr) :
        arr.append(d(i))

ans = []
for i in range(1, 10001):
    if not(i in arr):
        ans.append(i)
        print(i)
#print(ans)