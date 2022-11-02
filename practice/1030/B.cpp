// Baekjoon No. 6588 ∞ÒµÂπŸ»Â¿« √ﬂ√¯ - 221030 solved
// Time Complexity O(n^2)
// #brute force

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int prime(int n);
int main() {
	fastIO
	int n;
	int i;
	bool isWrong;
	while (1) {
		isWrong = true;
		cin >> n;
		if (!n) break;
		for (i = 3; i <= n / 2; i++) {
			if (prime(i) && prime(n - i)) {
				cout << n << " = " << i << " + " << n - i << "\n";
				isWrong = false;
				break;
			}
		}
		if (isWrong) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}
int prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}