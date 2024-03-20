#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
#define ll long long
using namespace std;

ll numbers[SIZE] = { 0 };
// 홀수의 개수 저장
ll segTree[SIZE * 4] = { 0 };

ll init(int nodeIdx, int st, int ed, int l, int r);
ll query(int nodeIdx, int st, int ed, int l, int r);
void modify(int nodeIdx, int st, int ed, int target, ll val);

int main() {
	fastIO;
	int n, q, p1, p2, t;
	ll v;
	int i;
	cin >> n >> q;
	for (i = 0; i < n; i++)
		cin >> numbers[i];
	init(1, 1, n, 1, n);
	for (i = 0; i < q; i++) {
		cin >> p1 >> p2 >> t >> v;
		// swaps p1 and p2
		if (p1 > p2) {
			p2 += p1;
			p1 = p2 - p1;
			p2 -= p1;
		}
		cout << query(1, 1, n, p1, p2) << "\n";
		modify(1, 1, n, t, v);
	}
	return 0;
}

ll init(int nodeIdx, int st, int ed, int l, int r) {
	if (st == ed) return segTree[nodeIdx] = numbers[st - 1];
	int mid = (st + ed) / 2;
	return segTree[nodeIdx] = init(nodeIdx * 2, st, mid, l, r) + init(nodeIdx * 2 + 1, mid + 1, ed, l, r);
}
// 홀수 개수만 출력, 짝수는 구간길이 - 홀수개수로 구하기
ll query(int nodeIdx, int st, int ed, int l, int r) {
	if (l <= st && ed <= r) return segTree[nodeIdx];
	if (ed < l || r < st) return 0;
	int mid = (st + ed) / 2;
	return query(nodeIdx * 2, st, mid, l, r) + query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
}
void modify(int nodeIdx, int st, int ed, int target, ll val) {
	if (st == ed) {
		segTree[nodeIdx] = val;
		return;
	}

	int mid = (st + ed) / 2;
	if (target > mid) modify(nodeIdx * 2 + 1, mid + 1, ed, target, val);
	else modify(nodeIdx * 2, st, mid, target, val);
	segTree[nodeIdx] = segTree[nodeIdx * 2] + segTree[nodeIdx * 2 + 1];
	return;
}