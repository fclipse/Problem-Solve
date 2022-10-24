// Baekjoon No. 23818 원수의 원수 221021
// Time Complexity
// #

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, t, a, b;
    int i;
    string relations[4] = { "Friend", "enemy", "Unknown", "Error" };
    cin >> n >> m >> k;
    vector<vector<int>> graph(n+1);
    for (i = 0; i < m; i++) {
        cin >> t >> a >> b;
        
        graph[a][b] = t;
        graph[b][a] = t;
    }
    for (i = 0; i < k; i++) {
        cin >> a >> b;

    }
    return 0;
}