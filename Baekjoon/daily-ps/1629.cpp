// BOJ 1629 - 곱셈, 221230 solved
// 분할 정복, dp 이용, long long overflow 주의
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

map<int, int> memory;
int exp(int a, int b, int c);

int main() {
	int a, b, c;
	
	cin >> a >> b >> c;
	if (c == 1) cout << 0;
	else cout << exp(a, b, c);

	return 0;
}

int exp(int a, int b, int c) {
	if (memory.find(b) != memory.end()) return memory[b];

	// memory에 없을 때
	if (b == 1) return memory[b] = a % c;
	
	// b > 1일때
	if (b & 1) {	// 홀수이면
		return memory[b] = (exp(a, b / 2, c) * (ll)a) % c * exp(a, b / 2, c) % c;
	}
	else {
		return memory[b] = exp(a, b / 2, c) * (ll)exp(a, b / 2, c) % c;
	}
}