// Baekjoon No. 1306 
// Time Complexity
/*
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define SIZE (int)1e6
using namespace std;

int luma[SIZE] = { 0 };
int segTree[SIZE * 4] = { 0 };

int init(int nodeIdx, int st, int ed, int l, int r);
int query(int nodeIdx, int st, int ed, int l, int r);

int main() {
	fastIO;
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> luma[i];
	}
	// solving
	init(1, 1, n, 1, n);
	for (int i = 0; i < n - 2 * m + 2; i++) {
		cout << query(1, i + 1, i + 2 * m - 1, 1, n) << " ";
	}
	return 0;
}
int init(int nodeIdx, int st, int ed, int l, int r) {
	if (st == ed) return segTree[nodeIdx] = luma[st - 1];
	int mid = (st + ed) / 2;
	return segTree[nodeIdx] = max(init(nodeIdx * 2, st, mid, l, r), init(nodeIdx * 2 + 1, mid + 1, ed, l, r));
}
int query(int nodeIdx, int st, int ed, int l, int r) {
	if (l <= st && ed <= r) return segTree[nodeIdx];
	if (ed < l || r < st) return 0;
	int mid = (st + ed) / 2;
	return max(query(nodeIdx * 2, st, mid, l, r), query(nodeIdx * 2, mid + 1, ed, l, r));
}