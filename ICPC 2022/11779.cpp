// Baekjoon No. 11779 최소비용 구하기 2 - 220930~
// Time Complexity
// #다익스트라

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, v1, v2, cost, st, ed;
    int i;
    cin >> n >> m;
    vector<vector<int>> node(n);
    vector<vector<int>> costs(n);
    vector<int> minCost(n, -1);
    vector<int> visited(n, 0);
    for (i = 0; i < m; i++) {
        cin >> v1 >> v2 >> cost;
        v1--; v2--;
        node[v1].push_back(v2);
        costs[v1].push_back(cost);
    }
    cin >> st >> ed;
    st--; ed--;
    
    // solving
    minCost[st] = 0;
    
    return 0;
}