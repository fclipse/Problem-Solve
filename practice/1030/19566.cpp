// Baekjoon No. 19566 수열의 구간 평균 - 221102 solved...
// Time Complexity
/*
* 수열에서 평균이 k인 구간의 개수를 구하는 문제.
* 얼핏 보면 시간복잡도를 O(n)으로 만드는 것이 불가능해 보이지만, 맵과 누적합을 이용해 구할 수 있다...
* 어떻게 문제해결방법을 떠올려야 하는지 아직도 이해가 잘 되지 않는 문제
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastIO
	int n, k;
	int i;
	long long ans, tmp;
	cin >> n >> k;
	vector<long long> arr(n);	// 누적합
	map<long long, long long> m;
	cin >> arr[0];
	for (i = 1; i < n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	// solving
	ans = 0;
	for (i = 0; i < n; i++) {
		tmp = arr[i] - (i + 1) * (long long) k;
		ans += m[tmp]++;
	}
	ans += m[0];
	cout << ans;

	return 0;
}