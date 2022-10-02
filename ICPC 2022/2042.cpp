// Baekjoon No. 2042 구간 합 구하기
// Time Complexity O(nlogn)
// # Segment Tree

#include <iostream>
#include <vector>
#define SIZE 1000000
using namespace std;

long long int segTree[SIZE * 4 + 1] = { 0 };
long long int numbers[SIZE] = { 0 };

long long int init(int nodeIdx, int st, int ed);
long long int query(int node, int st, int ed, int l, int r);
long long int modify(int node, int st, int ed, int b, long long int c);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    int i, a, b, c;
    cin >> n >> m >> k;
    
    for (i = 0; i < n; i++)
        cin >> numbers[i];
    
    init(1, 0, n - 1);  // init segment tree
    
    
    for (i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        // solving
        if (a == 1) {
            modify(1, 0, n - 1, --b, c);
        }
        else {
            cout << query(1, 0, n - 1, --b, --c) << "\n";
        }
    }
    
    return 0;
}

long long int init(int nodeIdx, int st, int ed) {
    int mid = (st + ed) / 2;
    if (st == ed) 
        return segTree[nodeIdx] = numbers[st];
    else 
        return segTree[nodeIdx] = init(nodeIdx * 2, st, mid) + init(nodeIdx * 2 + 1, mid + 1, ed);
    
}

long long int query(int node, int st, int ed, int l, int r) {
    if (ed < l || r < st) 
        return 0;
    if (l <= st && ed <= r) 
        return segTree[node];
    int mid = (st + ed) / 2;
    return query(2 * node, st, mid, l, r) + query(2 * node + 1, mid + 1, ed, l, r);
}
long long int modify(int node, int st, int ed, int b, long long int c) {
    int tmp;
    if (st == ed) {
        tmp = segTree[node];
        segTree[node] = c;
        return tmp;
    }
    int mid = (st + ed) / 2;
    if (b > mid) tmp = modify(node * 2 + 1, mid + 1, ed, b, c);
    else tmp = modify(node * 2, st, mid, b, c);
    segTree[node] += c - tmp;
    return tmp;
}