// Baekjoon No. 2357 - 최솟값과 최댓값 221012 solved
// Time Complexity O(nlogn)
// # segment tree
#include <iostream>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
#define INF 1000000000
using namespace std;

int minSegTree[SIZE*4] = {0};
int maxSegTree[SIZE*4] = {0};
int numbers[SIZE] = {0};

int minInit(int nodeIdx, int st, int ed);
int maxInit(int nodeIdx, int st, int ed);
int minQuery(int nodeIdx, int st, int ed, int l, int r);
int maxQuery(int nodeIdx, int st, int ed, int l, int r);

int main(){
    fastIO
    int n, m, a, b;
    int i;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        cin >> numbers[i];
    }

    // solving
    minInit(1, 1, n);
    maxInit(1, 1, n);
    for(i = 0; i < m; i++){
        cin >> a >> b;
        cout << minQuery(1, 1, n, a, b) << " " << maxQuery(1, 1, n, a, b) << "\n";
    }
}
int minInit(int nodeIdx, int st, int ed){
    if(st == ed) return minSegTree[nodeIdx] = numbers[st - 1];
    int mid = (st + ed) / 2;
    return minSegTree[nodeIdx] = min(minInit(nodeIdx * 2, st, mid), minInit(nodeIdx * 2 + 1, mid + 1, ed));
}
int maxInit(int nodeIdx, int st, int ed){
    if(st == ed) return maxSegTree[nodeIdx] = numbers[st - 1];
    int mid = (st + ed) / 2;
    return maxSegTree[nodeIdx] = max(maxInit(nodeIdx * 2, st, mid), maxInit(nodeIdx * 2 + 1, mid + 1, ed));
}
int minQuery(int nodeIdx, int st, int ed, int l, int r){
    if(l <= st && ed <= r) return minSegTree[nodeIdx];
    if(ed < l || r < st) return INF;
    int mid = (st + ed) / 2;
    return min(minQuery(nodeIdx * 2, st, mid, l, r), minQuery(nodeIdx * 2 + 1, mid + 1, ed, l, r));
}
int maxQuery(int nodeIdx, int st, int ed, int l, int r){
    if(l <= st && ed <= r) return maxSegTree[nodeIdx];
    if(ed < l || r < st) return 1;
    int mid = (st + ed) / 2;
    return max(maxQuery(nodeIdx * 2, st, mid, l, r), maxQuery(nodeIdx * 2 + 1, mid + 1, ed, l, r));
}