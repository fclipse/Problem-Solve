// Baekjoon No.
// Time Complexity
/*
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int main() {
	fastIO;
	int n, ans = 0;
	int i;
	cin >> n;
	vector<int> g(n);
	vector<int> d(n);
	vector<int> memory(10001, 0);
	map<int, int> m;
	for (i = 0; i < n; i++) {
		cin >> g[i] >> d[i];
		if (memory[d[i]] == 0) memory[d[i]] = g[i];
		else memory[d[i]] = max(memory[d[i]], g[i]);
		
	}
	for (i = 1; i <= 10000; i++)
		ans += memory[i];
	cout << ans;
	return 0;
}