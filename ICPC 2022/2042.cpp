// Baekjoon No. 2042 구간 합 구하기 - 221003 solved
// Time Complexity O(nlogn)
// # Segment Tree

#include <iostream>
#define SIZE 1000000
using namespace std;

long long int segTree[SIZE * 4] = { 0 };
long long int numbers[SIZE] = { 0 };

long long int init(int nodeIdx, int st, int ed);
long long int query(int node, int st, int ed, int l, int r);
long long int modify(int node, int st, int ed, int b, long long int c);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    int i, a, b;
    long long int c;
    cin >> n >> m >> k;

    // numbers array input
    for (i = 0; i < n; i++)
        cin >> numbers[i];
    
    init(1, 1, n);  // init segment tree
    
    for (i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        // solving
        if (a == 1) {
            modify(1, 1, n, b, c);
        }
        else {
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
    
    return 0;
}

long long int init(int nodeIdx, int st, int ed) {
    int mid = (st + ed) / 2;
    if (st == ed) 
        return segTree[nodeIdx] = numbers[st - 1];
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
    long long int tmp;
    if (st == ed) {
        tmp = segTree[node];
        segTree[node] = c;
    }
    else {
        int mid = (st + ed) / 2;
        tmp = (b > mid) ? modify(node * 2 + 1, mid + 1, ed, b, c) : modify(node * 2, st, mid, b, c);
        segTree[node] += c - tmp;
    }
    return tmp;
}