#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}

int main() {
	fastio;
	// inputs
	int n, m, sum = 0;
	cin >> n >> m;

	// 노드 간 거리 정보 저장하는 벡터, 인접 리스트 방식으로 저장
	// { nodeIdx, distance } 형식으로 저장됨
	vector<vector<pair<int, int>>> dist(n);
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		dist[a].push_back({ b, c });
		dist[b].push_back({ a, c });
	}

	// solving


	// result
	cout << sum;

	return 0;
}