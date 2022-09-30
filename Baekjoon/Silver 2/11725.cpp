// Baekjoon No. 11725 트리의 부모 찾기 - 220923~220924
// Time Complexity O(n)
// #tree traversal, dfs

#include <iostream>
#include <vector>
using namespace std;

void disconnect(vector<vector<int>>& node, vector<int>& visited, int n,  int nodeIdx);   // 해당 nodeIdx에 연결된 부모->자식 연결 끊어줌
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, child, parent;
    int i, j;
    cin >> n;
    vector<vector<int>>node(n);
    // map<int, vector<int>> node;
    vector<int> visited(n, 0);
    for (i = 0; i < n - 1; i++) {
        cin >> child >> parent;
        // 일단 부모->자식 자식->부모 모두 연결
        child--;
        parent--;
        
        node[child].push_back(parent);
        node[parent].push_back(child);
    }

    // solving
    /** 알고리즘 구상
    * 1) 노드 입력, 간선 양방향 연결
    * 2) 노드 1부터 DFS 진행하며 부모->자식 연결 끊어줌
    * 3) 결과 출력
    */
    disconnect(node, visited, n, 0);

    // output
    for (i = 1; i < n; i++) {
        for (j = 0; j < node[i].size(); j++) {
            if (node[i][j] >= 0) {
                cout << node[i][j] + 1<<"\n";
            }
            
        }
    }
    return 0;
}

void disconnect(vector<vector<int>>& node, vector<int>& visited, int n, int nodeIdx) {
    int i, size = node[nodeIdx].size(), nextIdx;
    // mark visited
    visited[nodeIdx] = 1;
    // finds if there is child node, and disconnects the connection
    // go to child node, and continues process
    for (i = 0; i < size; i++) {
        if (!visited[node[nodeIdx][i]] && node[nodeIdx][i] > 0) {
            nextIdx = node[nodeIdx][i];
            node[nodeIdx][i] = -1;
            disconnect(node, visited, n, nextIdx);
        }
    }
    return;
}