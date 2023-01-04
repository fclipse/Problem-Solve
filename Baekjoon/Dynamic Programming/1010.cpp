// BOJ 1010 - 다리 놓기, 221228 solved
// dp, 조합 dp로 구현하는 문제. nCr = n-1Cr-1 + n-1Cr
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define ll long long
using namespace std;

ll combination(int n, int m, vector<vector<ll>>& memory);

int main() {
	fastio;
	int t, n, m;
	cin >> t;
	for (; t > 0; t--) {
		cin >> n >> m;
		// solving
		vector<vector<ll>> memory(m + 1, vector<ll>(m + 1, 0));
		cout << combination(n, m, memory) << "\n";
	}

	return 0;
}
ll combination(int n, int m, vector<vector<ll>>& memory) {
	if (memory[n][m] > 0) return memory[n][m];
	if (n == 0 || m == n) return memory[n][m] = 1;
	return memory[n][m] = combination(n - 1, m - 1, memory) + combination(n, m - 1, memory);
}