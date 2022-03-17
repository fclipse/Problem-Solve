# 이전 tistory 자료 참고
### 백트래킹 기초 ###
n, m = map(int, input().split())

s = []
def dfs(k):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return

    for i in range(k, n + 1):
        if i not in s:
            s.append(i)
            dfs(i + 1)
            s.pop()
dfs(1)