// Baekjoon No. 1922 네트워크 연결 - 220930 solved
// Time Complexity O(nlogn)
// #최소신장트리, 크루스칼, 유니온 파인드

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> e1, vector<int> e2);
int find(vector<int>& point, int v1);
int unionFind(vector<int>& point, int v1, int v2);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, minCost, v1, v2, weight, size;
    int i;
    cin >> n >> m;
    vector<vector<int>> relations;
    vector<int> point(n);
    for (i = 0; i < n; i++)
        point[i] = i;
    for (i = 0; i < m; i++) {
        cin >> v1 >> v2 >> weight;
        v1--; v2--;
        if(v1 != v2)    // a != b
            relations.push_back({ v1, v2, weight });
    }
    
    // solving
    minCost = 0;
    size = relations.size();
    sort(relations.begin(), relations.end(), cmp);
            
    for (i = 0; i < size; i++) {
        if (unionFind(point, relations[i][0], relations[i][1])) {
            minCost += relations[i][2];
        }
    }
    
    // output
    cout << minCost;
    return 0;
}

// {{idx1, idx2, w1}, {}, ...{}}
bool cmp(vector<int> e1, vector<int> e2) {
    return e1[2] < e2[2];
}
int find(vector<int>& point, int v1) {
    if (point[v1] != v1)
        return find(point, point[v1]);
    return v1;
}
int unionFind(vector<int>& point, int v1, int v2) {
    int rootA = find(point, v1);
    int rootB = find(point, v2);
    if (rootA == rootB)
        return 0;
    else if (rootA > rootB) // point!
        point[rootA] = rootB;
    else
        point[rootB] = rootA;
    return 1;
}