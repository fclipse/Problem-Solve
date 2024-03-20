#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100000

using namespace std;

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int> honor(n);
	for (int i = 0; i < n; i++) {
		cin >> honor[i];
	}

	// solving
	int standard = 1;
	long long ans = 0;
	// 1. 수열을 정렬함
	sort(honor.begin(), honor.end());
	// 2. 돌면서 i번째 수에서 i + 1의 수를 각각 빼고, 같다면 넘김.
	for (int i = 0; i < n; i++) {
		// standard + 1 -> 원래 되어야 하는 숫자
		if (honor[i] == standard - 1) continue;
		ans += honor[i] - standard;
		standard++;
	}

	cout << ans;
	return 0;
}

/*
주어진 수열을 1~n까지의 수열로 만들기 위해 필요한 최소 차이를 구하는 문제.
알고리즘 진행 과정
1. 수열 정렬
2. i번째 수에서 standard(되어야 하는 숫자)를 뺀 만큼을 ans에 더함
3. standard를 1 증가시킴
- 단, 2. 에서 현재 숫자가 중복이면 넘어감(중복인 수는 고려 안해야 한다.)
- ans의 최댓값이 int범위 (약 2*10^8)을 넘어감으로 long long으로 선언해야 한다.
*/