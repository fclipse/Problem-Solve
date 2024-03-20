// BOJ 2193 - 이친수, 221228 solved
// dp, 피보나치랑 점화식 같음
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define SIZE 90
using namespace std;

int main() {
	int n;
	long long memory[2][SIZE] = { 0 };
	cin >> n;
	
	// solving
	memory[0][0] = 0;
	memory[1][0] = 1;
	for (int i = 1; i < n; i++) {
		memory[0][i] = memory[0][i - 1] + memory[1][i - 1];
		memory[1][i] = memory[0][i - 1];
	}

	cout << memory[0][n - 1] + memory[1][n - 1];

	return 0;
}