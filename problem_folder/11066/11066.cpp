#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10000

using namespace std;

// struct
typedef struct{
    long long cost;
    int p1, p2;
}Merge;

// globals
long long arr[SIZE] = {0};
int parent[SIZE] = {0};

// functions
int find(int n);
bool _union(int v, int w);

int main() {
	fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int k;
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> arr[i];
        }

        // solving
        long long minCost = 0;
        priority_queue<pair<long long, int>> q;
        for(int i = 0; i < k; i++) parent[i] = i;   // parent[] init
        
        while(q.size() <= 1){
            pair<Merge> t = q.top();
            q.pop();
            if(sum[t.second] != t.first) continue;
            // 맞다면
            int idx = t.second;
            minCost += t.first;
            if(idx > 0){
                sum[idx - 1] += t.first;
            }
        }

        // output
        cout << -minCost << "\n";
    }

	return 0;
}

int find(int n){
    if(n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}
bool _union(int v, int w){
    if(v < w) swap(v, w);
    int rv = find(v);
    int rw = find(w);
    if(rv == rw) return false;
    
    parent[rw] = parent[rv];
    return true;
}