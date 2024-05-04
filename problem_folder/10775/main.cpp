#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100001
using namespace std;

// globals
int maxGate[SIZE] = {0};
int parent[SIZE] = {0};

// functions
int find(int n);

int main() {
	fastio;
    int g, p;
    cin >> g >> p;
    for (int i = 0; i < p; i++){
        cin >> maxGate[i];
    }

    // solving
    int ans = 0;
    // init parent
    for (int i = 1; i <= g; i++){
        parent[i] = i;
    }
    for (int i = 0; i < p; i++){
        int minUnusedIdx = find(maxGate[i]);
        if(minUnusedIdx == 0) break;
        ans++;
        parent[minUnusedIdx] = find(minUnusedIdx - 1);   
    }

    // output
    cout << ans;
	return 0;
}

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}
