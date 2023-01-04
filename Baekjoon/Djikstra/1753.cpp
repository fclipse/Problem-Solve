// Baekjoon No. 1753 최단경로 - 221116~
// Time Complexity
/*
* #dijkstra
*/
#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF (int)2e9 + 7
#define SIZE 20001
using namespace std;

int dist[SIZE] = { 0 };
bool visited[SIZE] = { 0 };

void dijkstra(int k, vector<vector<pair<int, int>>> &edge);

int main() {
	fastIO;
	int V, E, start, u, v, w;
	cin >> V >> E >> start;
	// initialize
	vector<vector<pair<int, int>>> edge(V);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge[u - 1].push_back({ w, v - 1 });
	}
	for (int i = 0; i < V; i++) {
		dist[i] = INF;
	}

	// solve
	dijkstra(start - 1, edge);
	for (int i = 0; i < V; i++) {
		if (dist[i] >= INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
void dijkstra(int k, vector<vector<pair<int, int>>>& edge) {
	priority_queue<pair<int, int>> pqueue;
	pqueue.push({ 0, k });
	dist[k] = 0;
	while(!pqueue.empty()) {
		int stIdx = pqueue.top().second;
		pqueue.pop();
		if (visited[stIdx]) continue; 
		else visited[stIdx] = true;
		// dist값 update
		for (int i = 0; i < edge[stIdx].size(); i++) {
			int cost = edge[stIdx][i].first, idx = edge[stIdx][i].second;
			if (!visited[idx] && dist[idx] > dist[stIdx] + cost) {
				dist[idx] = dist[stIdx] + cost;
				pqueue.push({ -dist[idx], idx });
			}
		}
	}
	return;
}