// Baekjoon No. 10868 최솟값 - 221110 solved
// Time Complexity O(mlogn)
/* #Segment Tree
*  여러 구간에서의 최솟값을 구하는 문제
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define SIZE 100000
#define INF 1000000000	// 1 billion
using namespace std;

int numbers[SIZE] = { 0 };
int segTree[SIZE * 4] = { 0 };

int init(int nodeIdx, int st, int ed);
int query(int nodeIdx, int l, int r, int st, int ed);

int main() {
	fastIO;
	int n, m, a, b;
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> numbers[i];

	// solving
	init(1, 1, n);
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		cout << query(1, 1, n, a, b) << "\n";
	}

	return 0;
}

int init(int nodeIdx, int st, int ed) {
	if (st == ed) return segTree[nodeIdx] = numbers[st - 1];
	int mid = (st + ed) / 2;
	int leftMinVal = init(nodeIdx * 2, st, mid);
	int rightMinVal = init(nodeIdx * 2 + 1, mid + 1, ed);
	return segTree[nodeIdx] = min(leftMinVal, rightMinVal);
}

int query(int nodeIdx, int l, int r, int st, int ed) {
	if (st <= l && r <= ed) return segTree[nodeIdx];
	if (r < st || ed < l) return INF;
	int mid = (l + r) / 2;
	int leftMinVal = query(nodeIdx * 2, l, mid, st, ed);
	int rightMinVal = query(nodeIdx * 2 + 1, mid + 1, r, st, ed);
	return min(leftMinVal, rightMinVal);
}