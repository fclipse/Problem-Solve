// BOJ 1026 - 보물, 230102 solved
// @explaination - A에서는 가장 작은 수부터, B에서는 가장 큰 수부터 서로 곱해 가며 
// 합한 결과를 출력하면 되는 문제
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	// solving
	int res = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < n; i++) {
		res += A[n - i - 1] * B[i];
	}

	cout << res;
	return 0;
}