#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// functions
int find(int n, vector<int> & parentNode);
bool union_(int v, int w, vector<int> &parentNode);

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> stepInfo(m);
    vector<int> parentNode(n, 0);
    for(int i = 0; i < m; i++){
        cin >> stepInfo[i].first >> stepInfo[i].second;
    }

    // solving
    for(int i = 0; i < n; i++){
        parentNode[i] = i;
    }
    // output
    for(int i = 0; i < m; i++){
        int v = stepInfo[i].first, w = stepInfo[i].second;
        if(!union_(v, w, parentNode)){
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
}

// 부모 노드를 계속해서 타고 올라가 루트 노드를 찾는 연산
int find(int n, vector<int> & parentNode){
    if(parentNode[n] == n) return n;
    return find(parentNode[n], parentNode);
}

// 두 노드를 하나의 그룹으로 합칠 수 있는지 판정하고, 있다면 합치는 함수
bool union_(int v, int w, vector<int> &parentNode){
    int rv = find(v, parentNode), rw = find(w, parentNode);
    if(rv == rw) return false;

    parentNode[max(rv, rw)] = min(rv, rw);
    return true;
}