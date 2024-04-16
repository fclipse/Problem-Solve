#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// functions
int find(int n, vector<int> &arr);
bool union_(int v, int w, vector<int> &arr);

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<int> parentNode(n);
    vector<vector<pair<int, int>>> graph(n);
    priority_queue<pair<int, pair<int, int>>> pqueue;
    for(int i = 0; i < m; i++){
        int v, w, cost;
        cin >> v >> w >> cost;
        graph[v - 1].push_back({cost, w - 1});
        graph[w - 1].push_back({cost, v - 1});
        // costs init
        pqueue.push({-cost, {v - 1, w - 1}});
    }

    // solving
    int ans = 0;
    int lastCost = 0;
    for(int i = 0; i < n; i++){
        parentNode[i] = i;
    }
    while(!pqueue.empty()){
        pair<int, pair<int, int>> top = pqueue.top();
        pqueue.pop();
        int cost = -top.first;
        int v = top.second.first, w = top.second.second;
        if(union_(v, w, parentNode)){
           ans += cost;
           lastCost = cost;
        }
    }

    // output
    cout << ans - lastCost;

	return 0;
}

int find(int n, vector<int> &arr){
    if(arr[n] == n) return n;
    // path compression
    return arr[n] = find(arr[n], arr);
}

bool union_(int v, int w, vector<int> &arr){
    int rv = find(v, arr), rw = find(w, arr);
    if(rv == rw) return false;

    arr[max(rv, rw)] = min(rv, rw);
    return true;
}