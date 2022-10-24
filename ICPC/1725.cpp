// Baekjoon No.
// Time Complexity
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
using namespace std;

int segTree[SIZE * 4] = { 0 };
int heights[SIZE] = { 0 };
int maxSize = 0;
int n;

int init(int, int, int);
int query(int, int, int, int, int);
void solve(int, int);

int main() {
    fastIO;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> heights[i];
    init(1, 1, n);
    solve(1, n);
    cout << maxSize;
    return 0;
}

int init(int nodeIdx, int st, int ed) {
    if (st == ed) return segTree[nodeIdx] = st;
    int mid = (st + ed) / 2;
    int leftMinIdx = init(nodeIdx * 2, st, mid);
    int rightMinIdx = init(nodeIdx * 2 + 1, mid + 1, ed);
    return segTree[nodeIdx] = (heights[leftMinIdx - 1] > heights[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;
}
int query(int nodeIdx, int st, int ed, int l, int r) {
    if (r < st || ed < l) return 0;
    if (l <= st && ed <= r) return segTree[nodeIdx];
    int mid = (st + ed) / 2;
    int leftMinIdx = query(nodeIdx * 2, st, mid, l, r);
    int rightMinIdx = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
    if (leftMinIdx * rightMinIdx == 0) return leftMinIdx + rightMinIdx;
    return (heights[leftMinIdx - 1] > heights[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;
}
void solve(int st, int ed) {
    if (st > ed) return;
    int minIdx = query(1, 1, n, st, ed);
    maxSize = max(maxSize, heights[minIdx - 1] * (ed - st + 1));
    solve(st, minIdx - 1);
    solve(minIdx + 1, ed);
    return;
}