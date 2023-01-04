#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void combination(vector<vector<int>>* total_case, vector<int> elements, int n, int r, int idx);
int main() {
	fastio
		int t, n, k, m;
	cin >> t;
	for (; t > 0; t--) {
		vector<vector<int>> total_case;
		cin >> n >> k >> m;
		combination(&total_case, vector<int>(), n, n - k, 0);
		for (vector<int> v : total_case) {
			for (int e : v) {
				cout << e << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}

void combination(vector<vector<int>>* total_case, vector<int> elements, int n, int r, int idx) {
	if (n == r) {
		for (int i = idx; i < idx + r; i++) {
			elements.push_back(i);
		}
		total_case->push_back(elements);
	}
	else if (r == 0) {
		total_case->push_back(elements);
	}
	else {
		// n-1Cr
		combination(total_case, elements, n - 1, r, idx + 1);

		// n-1Cr-1
		elements.push_back(idx);
		combination(total_case, elements, n - 1, r - 1, idx + 1);
	}
	return;
}