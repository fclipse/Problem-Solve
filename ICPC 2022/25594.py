import sys
def recursion(x, y):
    global n, m, res, lst, dp
    if(dp[y][x] != -1):
        return dp[y][x]
    
    cnt = 0
    if(x > 0 and lst[y][x-1] > lst[y][x]):
        cnt += recursion(x-1, y)
    if(y > 0 and lst[y-1][x] > lst[y][x]):
        cnt += recursion(x, y-1)
    if(x < n-1 and lst[y][x+1] > lst[y][x]):
        cnt += recursion(x+1, y)
    if(y < m-1 and lst[y+1][x] > lst[y][x]):
        cnt += recursion(x, y+1)
    
    dp[y][x] = cnt
    return cnt

m, n = map(int, sys.stdin.readline().split())
lst = []
for i in range(m):
    lst.append(list(map(int, sys.stdin.readline().split())))

dp = [[-1 for j in range(n)] for i in range(m)]
dp[0][0] = 1

res = recursion(n-1, m-1)
print(res)