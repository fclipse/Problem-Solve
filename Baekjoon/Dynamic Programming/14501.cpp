// BOJ - Επ»η, 230113 solved
#include <bits/stdc++.h>
#define SIZE 15
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int memory[SIZE + 1] = { 0 };
int times[SIZE] = { 0 };
int prices[SIZE] = { 0 };

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> times[i] >> prices[i];
	}

	// solving
	int maxMemory = memory[0];
	for (int i = 0; i < n; i++) {
		int idx = times[i] + i - 1;
		if (idx <= n) {
			memory[idx] = max(memory[idx], maxMemory + prices[i]);
		}
		maxMemory = max(maxMemory, memory[i]);
	}
	cout << maxMemory;

	return 0;
}