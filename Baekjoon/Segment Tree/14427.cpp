// Baekjoon No. 14427 수열과 쿼리 15- 221112 solved
// Time Complexity
/* #Segment Tree
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
void modify(int nodeIdx, int st, int ed, int target, int val);

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
		cin >> order;
		if (order == 1) {
			cin >> p1 >> p2;
			modify(1, 1, n, p1, p2);
		}
		else {
			cout << query(1, 1, n, 1, n) << "\n";
		}
	}


	return 0;
}

int init(int nodeIdx, int st, int ed, int l, int r) {
	if (st == ed) return segTree[nodeIdx] = st;
	int mid = (st + ed) / 2;
	int leftMinIdx = init(nodeIdx * 2, st, mid, l, r);
	int rightMinIdx = init(nodeIdx * 2 + 1, mid + 1, ed, l, r);
	return segTree[nodeIdx] = (numbers[leftMinIdx - 1] > numbers[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;	// 순서 주의!
}
int query(int nodeIdx, int st, int ed, int l, int r) {
	if (l <= st && ed <= r) return segTree[nodeIdx];
	if (ed < l || r < st) return 0;
	int mid = (st + ed) / 2;
	int leftMinIdx = query(nodeIdx * 2, st, mid, l, r);
	int rightMinIdx = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
	if (leftMinIdx * rightMinIdx == 0) return leftMinIdx + rightMinIdx;
	return (numbers[leftMinIdx- 1] > numbers[rightMinIdx - 1]) ? rightMinIdx : leftMinIdx;
}
void modify(int nodeIdx, int st, int ed, int target, int val) {
	if (st == ed && st == target) {
		numbers[target - 1] = val;
		return;
	}
	int mid = (st + ed) / 2;
	if (target > mid) modify(nodeIdx * 2 + 1, mid + 1, ed, target, val);
	else modify(nodeIdx * 2, st, mid, target, val);
	int lIdx = segTree[nodeIdx * 2];
	int rIdx = segTree[nodeIdx * 2 + 1];
	segTree[nodeIdx] = (numbers[lIdx- 1] > numbers[rIdx - 1]) ? rIdx : lIdx;	// 무작정 갱신 x
	return;
}