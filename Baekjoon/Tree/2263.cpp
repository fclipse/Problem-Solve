#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio
	int n;
	cin >> n; 
	vector<int> pre_order(n);
	vector<int> in_order(n);
	vector<int> post_order(n);
	// input
	for (int i = 0; i < n; i++) cin >> in_order[i];
	for (int i = 0; i < n; i++) cin >> post_order[i];

	// solving
	


	return 0;
}