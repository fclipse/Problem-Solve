// BOJ 2748 - 피보나치 수 2, 221228 solved
// long long 및 array out of bound 조심..
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> memory(n + 1, 0);

	// solving
	memory[0] = 0;
	if(n > 0)
		memory[1] = 1;

	for (int i = 2; i <= n; i++) {
		memory[i] = memory[i - 1] + memory[i - 2];
	}

	// output
	cout << memory[n];
	return 0;
}