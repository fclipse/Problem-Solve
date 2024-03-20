// Baekjoon No. 10999 구간 합 구하기 2 - 221022~
// Time Complexity O(nlogn)
// #Segment tree, 구간 합

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;

int n;
long long numbers[SIZE] = { 0 };
long long lazy[SIZE * 4] = { 0 };
long long segTree[SIZE * 4] = { 0 };

long long init(int, int, int);
long long query(int, int, int, int, int);
long long modify(int, int, int, int, int, long long);

int main() {
    fastIO
    int m, k, a, b, c;
    int i;
    long long d;
    cin >> n >> m >> k;
    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // solving
    init(1, 1, n);
    for (i = 0; i < m + k; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            modify(1, 1, n, b, c, d);
        }
        else {
            cin >> b >> c;
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
    return 0;
}

long long init(int nodeIdx, int st, int ed) {
    if (st == ed) return segTree[nodeIdx] = numbers[st - 1];
    int mid = (st + ed) / 2;
    long long left = init(nodeIdx * 2, st, mid);
    long long right = init(nodeIdx * 2 + 1, mid + 1, ed);
    return segTree[nodeIdx] = left + right;
}
long long query(int nodeIdx, int st, int ed, int l, int r) {
    int length = (ed - st + 1);
    // 기존에 있던 lazy값 처리
    if (lazy[nodeIdx]) {
        segTree[nodeIdx] += lazy[nodeIdx] * length;
        if (st != ed) { // 자식노드 있다면
            lazy[nodeIdx * 2] += lazy[nodeIdx];
            lazy[nodeIdx * 2 + 1] += lazy[nodeIdx];
        }
        lazy[nodeIdx] = 0;
    }
    if (ed < l || r < st) return 0;
    if (l <= st && ed <= r) return segTree[nodeIdx];
    int mid = (st + ed) / 2;
    long long left = query(nodeIdx * 2, st, mid, l, r);
    long long right = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
    return left + right;
}
// return값은 새로 바꿔준 값에서 왼쪽, 오른쪽에 각각 더해준 값 합한 것. 범위 밖이면 0.
long long modify(int nodeIdx, int st, int ed, int l, int r, long long d) {
    int length = (ed - st + 1);
    // 기존에 있던 lazy값 처리
    if (lazy[nodeIdx]) {
        segTree[nodeIdx] += lazy[nodeIdx] * length;
        if (st != ed) { // 자식노드 있다면
            lazy[nodeIdx * 2] += lazy[nodeIdx];
            lazy[nodeIdx * 2 + 1] += lazy[nodeIdx];
        }
        lazy[nodeIdx] = 0;
    }
    if (ed < l || r < st) return 0; // 새로 더해주는 값 없으므로 0 return;
    if (l <= st && ed <= r) {
        // 새로 수 더해주는 부분, 만약 자식 노드 모두 구간에 포함될 때
        segTree[nodeIdx] += length * d;
        if (st != ed) { // 자식노드 있다면
            lazy[nodeIdx * 2] += d;
            lazy[nodeIdx * 2 + 1] += d;
        }
        return length * d;
    }
    int mid = (st + ed) / 2;
    // 새로 자식 노드들에게서 더해준 값들 합 현재 노드에 더해줌.
    long long leftVal = modify(nodeIdx * 2, st, mid, l, r, d);
    long long rightVal = modify(nodeIdx * 2 + 1, mid + 1, ed, l, r, d);
    segTree[nodeIdx] += leftVal + rightVal;
    return leftVal + rightVal;
}