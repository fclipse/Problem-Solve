# 하노이의 탑 이동 횟수, 과정 출력하는 프로그램
def hanoi(n, a, b):
    if n == 1:
        print(a, b)
        return
    else:
        arr = []
        arr.extend([a, b])
        notin = [x for x in range(1, 4) if x not in arr]    # 리스트에 없는 수만 가져오는 코드
        hanoi(n-1, a, notin[0]) # ILovePython
        print(a, b)             # IDEA : k개를 옮길 때 k-1개를 2번째로 먼저 옮긴 다음 k번째를 3번째에 옮기고 나머지를 3번째에 옮김.
        hanoi(n-1, notin[0], b)
        return

n = int(input())
print(2**n - 1)
hanoi(n, 1, 3)