n, m = map(int, input().split())

lst = []
def dfs(k):
    if len(lst) == m:
        print(' '.join(map(str, lst)))
        return
    
    for i in range(k, n + 1):
        lst.append(i)
        dfs(i)
        lst.pop()

dfs(1)