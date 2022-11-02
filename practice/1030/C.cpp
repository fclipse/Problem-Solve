// Baekjoon No. 2435 기상청 인턴 신현수 - 221030 solved
// Time Complexity 
// #brute force

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int arr[101] = { 0 };
int main() {
	fastIO
	int n, k, tmp, maxVal = -300;
	int i, j;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// solving
	for (i = 0; i < n - k + 1; i++) {
		tmp = 0;
		for (j = 0; j < k; j++) tmp += arr[i + j];
		if (tmp > maxVal) maxVal = tmp;
	}
	cout << maxVal;
}