#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
#define ll long long
using namespace std;

// int numbers[SIZE] = { 0 };
// 홀수의 개수 저장
ll segTree[SIZE * 4] = { 0 };

ll query(int nodeIdx, int st, int ed, int l, int r);
void modify(int nodeIdx, int st, int ed, int target, ll val);

int main() {
	fastIO;
	int n, q, type, p1, p2;
	int i;
	cin >> n >> q;
	for (i = 0; i < q; i++) {
		cin >> type >> p1 >> p2;
		if (type == 1) modify(1, 1, n, p1, p2);
		else cout << query(1, 1, n, p1, p2) << "\n";
	}
	return 0;
}

ll query(int nodeIdx, int st, int ed, int l, int r) {
	if (l <= st && ed <= r) return segTree[nodeIdx];
	if (ed < l || r < st) return 0;
	int mid = (st + ed) / 2;
	return query(nodeIdx * 2, st, mid, l, r) + query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
}
void modify(int nodeIdx, int st, int ed, int target, ll val) {
	if (st == ed) {
		segTree[nodeIdx] += val;
		return;
	}

	int mid = (st + ed) / 2;
	if (target > mid) modify(nodeIdx * 2 + 1, mid + 1, ed, target, val);
	else modify(nodeIdx * 2, st, mid, target, val);
	segTree[nodeIdx] = segTree[nodeIdx * 2] + segTree[nodeIdx * 2 + 1];
	return;
}