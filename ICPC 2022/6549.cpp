// Baekjoon No. 6549 - 히스토그램에서 가장 큰 직사각형 221001~ 221022
// Time Complexity O(nlogn)
// # Segment Tree, # Divide and Conquer

#include <bits/stdc++.h>
#define SIZE 100000
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
long long int maxSize;
int heights[SIZE] = { 0 };
int segTree[SIZE * 4] = { 0 };

int init(int nodeIdx, int st, int ed);
int query(int nodeIdx, int st, int ed, int l, int r);
void solve(int, int, int);

using namespace std;
int main() {
    fastIO
    int n;
    int i;
    cin >> n;
    while (n > 0) {
        maxSize = 0;
        for (i = 0; i < n; i++)
            cin >> heights[i];
        init(1, 1, n);

        // solve
        solve(1, n, n);

        // output
        cout << maxSize << "\n";
        cin >> n;
    }
    return 0;
}
// 최소 높이 인덱스 반환
int init(int nodeIdx, int st, int ed) {
    if (st == ed) return segTree[nodeIdx] = st;
    int mid = (st + ed) / 2;
    int leftMinIdx = init(nodeIdx * 2, st, mid);
    int rightMinIdx = init(nodeIdx * 2 + 1, mid + 1, ed);
     
    return segTree[nodeIdx] = (heights[leftMinIdx - 1] > heights[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;
}
// 구간 내의 최소인덱스 반환 -> heights 인덱스
int query(int nodeIdx, int st, int ed, int l, int r) {
    if (ed < l || r < st) return 0;   // not in the range
    if (l <= st && ed <= r) return segTree[nodeIdx];
    
    int mid = (st + ed) / 2;
    int leftMinIdx = query(nodeIdx * 2, st, mid, l, r);
    int rightMinIdx = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
    // if (leftMinIdx * rightMinIdx == 0) return rightMinIdx + leftMinIdx; // 둘 중 하나가 0이면 다른 하나를 return함
    if (leftMinIdx * rightMinIdx == 0) return (leftMinIdx == 0) ? rightMinIdx : leftMinIdx;
    return (heights[leftMinIdx - 1] > heights[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;
}
// 구간 내 maxSize를 return하는 함수
void solve(int st, int ed, int n) {
    if (st > ed) return;
    int minIdx = query(1, 1, n, st, ed);
    if (minIdx == 0) return;
    maxSize = max(maxSize, (long long)heights[minIdx - 1] * (ed - st + 1));
    solve(st, minIdx - 1, n);
    solve(minIdx + 1, ed, n);
    return;
}