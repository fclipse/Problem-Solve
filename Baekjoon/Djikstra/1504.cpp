// BOJ 1504 - 특정한 최단 경로, 221228 solved
// 다익스트라 3번, 각각 총 2 case에 쓰는 문제
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define INF 2100000000
#define ll long long
using namespace std;

void dijkstra(int n, vector<ll>& dist, vector<vector<pair<ll, ll>>>& node);

int main() {
	fastio;
	ll n, e, v1, v2;
	ll res1 = 0, res2 = 0;
	bool isSuccess = true;
	cin >> n >> e;
	vector<vector<pair<ll, ll>>> node(n);
	for (int i = 0; i < e; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		node[a - 1].push_back({ c, b - 1 });	// weight, idx
		node[b - 1].push_back({ c, a - 1 });
	}
	cin >> v1 >> v2;

	// solving
	// 1 -> v1
	vector<ll> dist(n, INF);
	dijkstra(0, dist, node);
	if (dist[v1 - 1] != INF) { 
		res1 += dist[v1 - 1];
	}
	else isSuccess = false;

	// v1 -> v2
	if (isSuccess) {
		dist = vector<ll>(n, INF);
		dijkstra(v1 - 1, dist, node);
		if (dist[v2 - 1] != INF) res1 += dist[v2 - 1];
		else isSuccess = false;
	}	

	// v2 -> n
	if (isSuccess) {
		dist = vector<ll>(n, INF);
		dijkstra(v2 - 1, dist, node);
		if (dist[n - 1] != INF) res1 += dist[n - 1];
		else isSuccess = false;
	}

	// 1 -> v2 -> v1 -> N
	isSuccess = true;
	dist = vector<ll>(n, INF);
	dijkstra(0, dist, node);
	if (dist[v2 - 1] != INF) res2 += dist[v2 - 1];
	else isSuccess = false;

	if (isSuccess) {
		dist = vector<ll>(n, INF);
		dijkstra(v2 - 1, dist, node);
		if (dist[v1 - 1] != INF) res2 += dist[v1 - 1];
		else isSuccess = false;
	}

	if (isSuccess) {
		dist = vector<ll>(n, INF);
		dijkstra(v1 - 1, dist, node);
		if (dist[n - 1] != INF) res2 += dist[n - 1];
		else isSuccess = false;
	}

	// output
	if (isSuccess) {
		cout << min(res1, res2);
	}else {
		cout << -1;
	}
	return 0;
}

void dijkstra(int n, vector<ll>& dist, vector<vector<pair<ll, ll>>>& node) {
	int length = node.size();
	int stIdx = n;
	vector<bool> visited(length, 0);
	priority_queue<pair<ll, ll>> pqueue;

	// init
	dist[stIdx] = 0;
	pqueue.push({ -dist[stIdx], stIdx });

	// solving
	while(pqueue.size() > 0) {
		// select min Idx
		stIdx = pqueue.top().second;
		while (visited[stIdx]) {
			pqueue.pop();
			if (pqueue.empty()) return;	// end
			stIdx = pqueue.top().second;
		}
		pqueue.pop();
		visited[stIdx] = true;
		
		// updates dist for each connected vertex
		for (int i = 0; i < node[stIdx].size(); i++) {
			ll next = node[stIdx][i].second;
			ll weight = node[stIdx][i].first;
			if (!visited[next] && dist[next] > dist[stIdx] + weight) {
				dist[next] = dist[stIdx] + weight;
				pqueue.push({ -dist[next], next });
			}
		}
	}

	return;
}