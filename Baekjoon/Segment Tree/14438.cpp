// Baekjoon No. 14438 수열과 쿼리 17 - 221112 solved
// Time Complexity
/*
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define INF 1000000000
#define SIZE 100000
using namespace std;

int numbers[SIZE] = { 0 };
int segTree[SIZE * 4] = { 0 };

int init(int nodeIdx, int st, int ed, int l, int r);
int query(int nodeIdx, int st, int ed, int l, int r);
int modify(int nodeIdx, int st, int ed, int target, int val);

int main() {
	fastIO;
	int n, m, order, p1, p2;
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> numbers[i];
	
	init(1, 1, n, 1, n);
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> order >> p1 >> p2;
		if (order == 1) {
			modify(1, 1, n, p1, p2);
		}
		else {
			cout << query(1, 1, n, p1, p2) << "\n";
		}
	}


	return 0;
}

int init(int nodeIdx, int st, int ed, int l, int r) {
	if (st == ed) return segTree[nodeIdx] = numbers[st - 1];
	int mid = (st + ed) / 2;
	int leftMinVal = init(nodeIdx * 2, st, mid, l, r);
	int rightMidVal = init(nodeIdx * 2 + 1, mid + 1, ed, l, r);
	return segTree[nodeIdx] = min(leftMinVal, rightMidVal);
}
int query(int nodeIdx, int st, int ed, int l, int r) {
	if (l <= st && ed <= r) return segTree[nodeIdx];
	if (ed < l || r < st) return INF;
	int mid = (st + ed) / 2;
	int leftMinVal = query(nodeIdx * 2, st, mid, l, r);
	int rightMinVal = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
	return min(leftMinVal, rightMinVal);
}
int modify(int nodeIdx, int st, int ed, int target, int val) {
	int tmp = segTree[nodeIdx];
	if (st == ed && st == target) {
		segTree[nodeIdx] = val;
		return val - tmp;
	}
	int mid = (st + ed) / 2;
	if (target > mid) tmp = modify(nodeIdx * 2 + 1, mid + 1, ed, target, val);
	else tmp = modify(nodeIdx * 2, st, mid, target, val);
	segTree[nodeIdx] = min(segTree[nodeIdx * 2], segTree[nodeIdx * 2 + 1]);	// 무작정 갱신 x
	return tmp;
}