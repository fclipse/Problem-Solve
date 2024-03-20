#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int test = 0; test < t; test++) {
		// 각 case마다 진행
		cin >> n;
		vector<int> data(n);
		vector<int> memory(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}

		// solving
		memory[0] = data[0];


		// output

	}

	return 0;
}