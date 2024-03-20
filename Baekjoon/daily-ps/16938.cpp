#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main() {
	fastio
	int N, L, R, X;
	vector<int> levels(N);
	vector<int> sector_sum(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> levels[i];
		if (i == 0) sector_sum[i] = levels[i];
		else sector_sum[i] = levels[i] + sector_sum[i - 1];
	}
	
	// solving



	return 0;
}