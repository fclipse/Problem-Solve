#include<iostream>
#include<queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	int t[100001] = { 0, };

	queue<int> q;

	cin >> N >> K;
	q.push(N);
	t[N] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == K) {
			cout << t[x] - 1;
			break;
		}
		
		if (x - 1 > 0 && x - 1 < 100001) {
			if (!t[x - 1]) {
				t[x - 1] = t[x] + 1;
				q.push(x - 1);
			}
		}
		if (x + 1 > 0 && x + 1 < 100001) {
			if (!t[x + 1]) {
				t[x + 1] = t[x] + 1;
				q.push(x + 1);
			}
		}
		if (x * 2 > 0 && 2 * x < 100001) {
			if (!t[x * 2]) {
				t[x * 2] = t[x] + 1;
				q.push(x * 2);
			}
		}
	}
	return 0;
}