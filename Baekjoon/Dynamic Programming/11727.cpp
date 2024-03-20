// BOJ 11717 - 2n 타일링 2, 221228 solved
// dp, 두 칸 전에 올 수 있는 경우의 수를 2번 더해주는게 포인트 (2*2블록 하나 추가되었으므로)
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define NUM 10007
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> memory(n, 0);
	
	// solving
	memory[0] = 1;
	memory[1] = 3;
	
	for (int i = 2; i < n; i++) {
		memory[i] = (memory[i - 1] + 2 * memory[i - 2]) % NUM;
	}

	// output
	cout << memory[n - 1];
	return 0;
}