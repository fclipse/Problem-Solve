# 원의 접점의 개수를 구하는 프로그램
import sys, math
t =int(input())
for i in range(t):      # ** MISS 처음에 상수넣어서 실수한거 계속 못봄. 계속 시도도 못하고 오류나면 전체적으로 한번 살펴보기.
    x1, y1, r1, x2, y2, r2 = list(map(int, sys.stdin.readline().split()))
    distance = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
    
    if distance > r1 + r2:
        print(0)
    elif distance == r1 + r2: # 외접
        print(1)
    elif max(r1, r2) <= distance < r1 + r2:  # 원 밖의 두 점에서 만나는 경우
        print(2)
    else:
        if distance > abs(r1 - r2): # 원 안에서의 두 점에서 만나는 경우
            print(2)
        elif distance == abs(r1 - r2) and distance != 0:   # 내접 ** 0 이 아닐 때 !!!
            print(1)
        else:  # 원 안에 있으면서 만나지 않는 경우
            if distance == 0 and r1 == r2:
                print(-1)
            else:
                print(0)