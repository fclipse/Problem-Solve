#include <bits/stdc++.h>
#define SIZE 9
#define vint vector<int>
using namespace std;

void solve(vint heights);

int main() {
	vector<int> heights(SIZE);
	for (int i = 0; i < 9; i++) {
		cin >> heights[i];
	}

	// solving
	solve(heights);
	return 0;
}

void solve(vector<int> heights) {
	for (int p1 = 0; p1 < SIZE; p1++) {
		for (int p2 = p1 + 1; p2 < SIZE; p2++) {
			int res = 0;
			vector<bool> select(SIZE, 1);
			select[p1] = 0;
			select[p2] = 0;

			for (int i = 0; i < SIZE; i++) {
				if (select[i]) {
					res += heights[i];
				}
			}
			// 찾았을 시
			if (res == 100) {
				vint result(7, 0);
				int idx = 0;
				for (int i = 0; i < SIZE; i++) {
					if (select[i]) {
						result[idx] = heights[i];
						idx++;
					}
				}
				sort(result.begin(), result.end());
				for (int i = 0; i < result.size(); i++) {
					cout << result[i] << "\n";
				}
				return;
			}
		}
	}
	
}