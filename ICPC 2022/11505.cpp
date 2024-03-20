// Baekjoon No. 11505 구간 곱 구하기
// Time Complexity
// #

#include <iostream>
#define SIZE 1000000    // SIZE 범위 잘못쓴거 고침
#define VAL 1000000007

long long segTree[SIZE * 4] = { 0 };    // 1~n까지 인덱싱
int numbers[SIZE] = { 0 };

long long init(int nodeIdx, int st, int ed);
void modify(int nodeIdx, int st, int ed, int b, long long c);
long long query(int nodeIdx, int st, int ed, int l, int r);

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    int i, a, b;
    long long c;
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        cin >> numbers[i];
    init(1, 1, n);
    
    for (i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) modify(1, 1, n, b, c);
        else cout << query(1, 1, n, b, c) << "\n";
    }
    return 0;
}
long long init(int nodeIdx, int st, int ed) {
    if (st == ed) return segTree[nodeIdx] = numbers[st - 1];
    int mid = (st + ed) / 2;
    return segTree[nodeIdx] = init(nodeIdx * 2, st, mid) * init(nodeIdx * 2 + 1, mid + 1, ed) % VAL;
}
void modify(int nodeIdx, int st, int ed, int b, long long c) {
    int mid = (st + ed) / 2;
    if (st == ed)
        segTree[nodeIdx] = c;
    else {    // 0일때 처리 포함되어 있음
        (b > mid) ? modify(nodeIdx * 2 + 1, mid + 1, ed, b, c) : modify(nodeIdx * 2, st, mid, b, c);
        segTree[nodeIdx] = segTree[nodeIdx * 2] * segTree[nodeIdx * 2 + 1] % VAL;
    }
    return;
}
long long query(int nodeIdx, int st, int ed, int l, int r) {
    int mid = (st + ed) / 2;
    if (ed < l || r < st) return 1;
    else if (l <= st && ed <= r) return segTree[nodeIdx];
    else return query(nodeIdx * 2, st, mid, l, r) * query(nodeIdx * 2 + 1, mid + 1, ed, l, r) % VAL;
}