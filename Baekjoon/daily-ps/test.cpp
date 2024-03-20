#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio;
	for (;;) {
		int a, b;
		cin >> a >> b;
		cout << (a % b + b) % b << "\n";
	}

}