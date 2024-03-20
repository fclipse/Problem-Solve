// BOJ 10865 - 模备 模备, 221224 solved
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	int n, m;
	int a, b;
	cin >> n >> m;
	vector<int> friendsNum(n, 0);
	// init
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		friendsNum[a - 1]++;
		friendsNum[b - 1]++;
	}
	// output
	for (int i = 0; i < n; i++) {
		cout << friendsNum[i] << "\n";
	}

	return 0;
}