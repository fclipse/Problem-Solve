// Baekjoon No. 2268 수들의 합 7
// Time Complexity O(mlogn)
/* #Segment Tree
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define SIZE 1000000
#define ll long long
using namespace std;

ll segTree[SIZE * 4] = { 0 };
ll modify(int nodeIdx, int st, int ed, int target, ll val);
ll query(int nodeIdx, int st, int ed, int l, int r);

int main() {
	fastIO;
	int n, m, ctrl, p1, p2;
	int i;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> ctrl >> p1 >> p2;
		if (ctrl) modify(1, 1, n, p1, p2);
		else {
			if (p1 > p2) {	// 이것 추가 안해줘서... 문제를 잘 읽자!
				int tmp = p2;
				p2 = p1;
				p1 = tmp;
			}
			cout << query(1, 1, n, p1, p2) << "\n";
		}
	}

	return 0;
}

ll modify(int nodeIdx, int st, int ed, int target, ll val) {
	ll tmp = segTree[nodeIdx];	// segTree값 받아오는 변수는 segTree랑 자료형 같게 해주자..
	if (st == ed && st == target) {
		segTree[nodeIdx] = val;
		return val - tmp;
	}
	int mid = (st + ed) / 2;
	if (mid < target) tmp = modify(nodeIdx * 2 + 1, mid + 1, ed, target, val);
	else tmp = modify(nodeIdx * 2, st, mid, target, val);
	segTree[nodeIdx] += tmp;
	return tmp;
}
ll query(int nodeIdx, int st, int ed, int l, int r) {
	if (l <= st && ed <= r) return segTree[nodeIdx];
	if (ed < l || r < st) return 0;
	int mid = (st + ed) / 2;
	ll leftVal = query(nodeIdx * 2, st, mid, l, r);
	ll rightVal = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
	return leftVal + rightVal;
}