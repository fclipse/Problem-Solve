// Baekjoon No. 1012 ¿Ø±‚≥Û πË√ﬂ - 221030 solved
// Time Complexity O(n^2)
// #dfs, bfs

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 51
using namespace std;

int n, m;
int field[SIZE][SIZE] = { 0 };
int visited[SIZE][SIZE] = { 0 };

void dfs(int, int);

int main() {
    fastIO
    int t, k, res;
    int i, j, x, y;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        // field initialize
        res = 0;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                field[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        // inputs
        cin >> m >> n >> k;
        for (i = 0; i < k; i++) {
            cin >> x >> y;
            field[y][x] = 1;
        }

        // solving
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (!visited[i][j] && field[i][j]) {
                    dfs(j, i);
                    res++;
                }
            }
        }
        
        cout << res << "\n";
    }
    return 0;
}

void dfs(int x, int y) {
    visited[y][x] = 1;
    if (x > 0 && !visited[y][x - 1] && field[y][x - 1])
        dfs(x - 1, y);
    if (y > 0 && !visited[y - 1][x] && field[y - 1][x])
        dfs(x, y - 1);
    if (x < m && !visited[y][x + 1] && field[y][x + 1])
        dfs(x + 1, y);
    if (y < n && !visited[y + 1][x] && field[y + 1][x])
        dfs(x, y + 1);
    return;
}