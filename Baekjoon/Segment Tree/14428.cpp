// Baekjoon No. 14428 수열과 쿼리 - 221023 solved
// Time Complexity O(mlogn)
// #segment tree
/**
* 구간에서 임의의 숫자가 계속 변동이 있을 때도 구간의 최솟값 인덱스를 출력하는 알고리즘.
* 세그먼트 트리 사용
*/ 


#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
using namespace std;

int n;
int numbers[SIZE] = { 0 };
int segTree[SIZE * 4] = { 0 };

int init(int, int, int);
int query(int, int, int, int, int);
void modify(int, int, int, int, int);

int main() {
    fastIO;
    int m, a, b, c;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> numbers[i];
    init(1, 1, n);
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1)  modify(1, 1, n, b, c);
        else cout << query(1, 1, n, b, c) << "\n";
    }
    return 0;
}
// inits segment tree
int init(int nodeIdx, int st, int ed) {
    if (st == ed) return segTree[nodeIdx] = st;
    int mid = (st + ed) / 2;
    int leftMinIdx = init(nodeIdx * 2, st, mid);
    int rightMinIdx = init(nodeIdx * 2 + 1, mid + 1, ed);
    return segTree[nodeIdx] = (numbers[leftMinIdx - 1] > numbers[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;
}
// finds lowest number's index in range
int query(int nodeIdx, int st, int ed, int l, int r) {
    if (r < st || ed < l) return 0;
    if (l <= st && ed <= r) return segTree[nodeIdx];
    int mid = (st + ed) / 2;
    int leftMinIdx = query(nodeIdx * 2, st, mid, l, r);
    int rightMinIdx = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
    if (leftMinIdx * rightMinIdx == 0) return leftMinIdx + rightMinIdx;
    return (numbers[leftMinIdx - 1] > numbers[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;
}
// modifies ith index of numbers to v in segment tree
void modify(int nodeIdx, int st, int ed, int i, int v) {
    int mid = (st + ed) / 2;
    if (st == ed) {
        numbers[i - 1] = v;
        return;
    }else {
        if (mid < i) modify(nodeIdx * 2 + 1, mid + 1, ed, i, v);
        else modify(nodeIdx * 2, st, mid, i, v);
        segTree[nodeIdx] = (numbers[segTree[nodeIdx * 2] - 1] > numbers[segTree[nodeIdx * 2 + 1] - 1]) ? segTree[nodeIdx * 2 + 1] : segTree[nodeIdx * 2];
    }
    return;
}