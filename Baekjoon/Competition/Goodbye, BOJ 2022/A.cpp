// BOJ - Επ»η, 230113 solved
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int determine(int n);
int divisorSum(int n);

int main() {
	fastio;
	int t;
	cin >> t;
	for (; t > 0; t--) {
		int n, total = 0;
		cin >> n;
		if (determine(n)) cout << "Good Bye\n";
		else cout << "BOJ 2022\n";
	}
	
	return 0;
}

int determine(int n) {
	if (divisorSum(n) <= n) return 0;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			if (divisorSum(i) > i) return 0;
			if (i != n / i && divisorSum(n / i) > n / i) return 0;
		}
	}
	return 1;
}


int divisorSum(int n) {
	int res = 0;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			res += i;
			if (i != n / i) res += n / i;
		}
	}
	return res;
}