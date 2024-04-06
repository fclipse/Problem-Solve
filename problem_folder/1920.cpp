#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;

	int n, m;
	// n input
	cin >> n;
	map<int, bool> mpp;

	// arr: a input
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		mpp[tmp] = true;
	}
	// m input
	cin >> m;
	vector<int> target(m);
	// arr: target input
	for (int i = 0; i < m; i++) {
		cin >> target[i];
	}

	// solving
	for (int i = 0; i < m; i++) {
		if (mpp.find(target[i]) != mpp.end()) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}