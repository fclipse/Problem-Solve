# 1697 숨바꼭질
# DP문제
n, k = map(int, input().split())
if n == k :
    print(0)
elif n > k:
    print(n-k)
else:
    lst = [-1] * (2 * k)
    lst[n] = 0                      # n 자리 초기화
    for i in range(n):              # 0~ n-2 초기화
        lst[n-i-1] = lst[n-i] + 1
    for i in range(2*k-n-1):
        temp = []
        if n+i > 0 and lst[n+i] >= 0:
            temp.append(lst[n+i] + 1)
        if n+i+2 < 2*k-1 and lst[n+i+2] >= 0:
            temp.append(lst[n+i+1] + 1)
        if (n+i+1) % 2 == 0:
            temp.append(lst[(n+i+1)//2] + 1)
        
        if temp:
            lst[n+i+1] = min(temp)
        else:
            print(n+i, '고립')
    
    print(lst[k])
#print(lst)