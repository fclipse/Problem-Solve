// Baekjoon No. 11404 플로이드
// Time Complexity O(n^3)
/*	Floyd-Warshall
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1e9 + 7
#define ll long long
using namespace std;


void floydWarshall(int V, vector<vector<int>>& edge, vector<vector<ll>>& dist);
int main() {
	fastIO;
	// declare
	int n, m, a, b, c;
	// initialize
	cin >> n >> m;
	vector<vector<int>> edge(n, vector<int>(n, 0));
	vector<vector<ll>> dist(n, vector<ll>(n, 0));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (edge[a - 1][b - 1]) edge[a - 1][b - 1] = min(edge[a - 1][b - 1], c);
		else edge[a - 1][b - 1] = c;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (edge[i][j])
				dist[i][j] = edge[i][j];
			else
				dist[i][j] = INF;
		}
	}

	// solving
	floydWarshall(n, edge, dist);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] < INF) cout << dist[i][j] << " ";
			else cout << 0 << " ";
		}
		cout << "\n";
	}

	return 0;
}

void floydWarshall(int V, vector<vector<int>>& edge, vector<vector<ll>>& dist) {
	for (int stIdx = 0; stIdx < V; stIdx++) {
		for (int u = 0; u < V; u++) {
			for (int v = 0; v < V; v++) {
				if (u == v || stIdx == u || stIdx == v) continue;
				dist[u][v] = min(dist[u][v], dist[u][stIdx] + dist[stIdx][v]);
			}
		}
	}
	return;
}