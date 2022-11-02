// Baekjoon No. 1699 제곱수의 합 - 221030 solved
// Time Complexity 
// #DP
/*
* n을 표현할 수 있는 가장 작은 제곱수의 합의 개수를 구하는 문제.
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main() {
	fastIO
	int n, res, tmp, pivot;
	int i;
	cin >> n;
	vector<int> memory(n + 1, -1);
	memory[0] = 0;
	memory[1] = 1;
	for (i = 2; i <= n; i++) {
		pivot = 1;
		while (i - pivot * pivot >= 0) {
			if (memory[i] < 0 || memory[i] > memory[i - pivot * pivot] + 1) {
				memory[i] = memory[i - pivot * pivot] + 1;
			}
			pivot++;
		}
	}
	
	cout << memory[n];
	return 0;
}