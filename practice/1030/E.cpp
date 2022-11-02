// Baekjoon No. 15873
// Time Complexity 
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main() {
	fastIO
	int a, b;
	cin >> a;
	if (a < 100) {
		b = a % 10;
		a /= 10;
		
	}
	else if (a < 1000) {
		if (a % 10 == 0) {
			b = 10;
			a /= 100;
		}
		else {
			b = a % 10;
			a = 10;
		}
	}
	else {
		b = a % 100;
		a /= 100;
	}
	cout << a + b;
	return 0;
}