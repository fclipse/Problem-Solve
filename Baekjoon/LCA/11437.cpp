#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 500001
using namespace std;

int main() {
	fastIO;
	int n, m;
	cin >> n;
	vector<int> parent(n + 1, NULL);			// parent 정보 저장
	vector<vector<int>> child(n + 1);	// child 정보 배열로 저장
	parent[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		if (parent[u] = NULL) {
			parent[u] = v;
			child[v].push_back(u);
		}else {
			parent[v] = u;
			child[u].push_back(v);
		}
	}

	// solving
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, current_nodeIdx;
		int u_length, v_length;
		int lca = -1;

		int path_u[SIZE] = { 0 }, path_v[SIZE] = { 0 };
		cin >> u >> v;
		
		
		// u 부모들 배열 만듦
		current_nodeIdx = u;
		for (u_length = 0; parent[current_nodeIdx] != 0; u_length++) {
			path_u[u_length] = parent[current_nodeIdx];
			current_nodeIdx = parent[current_nodeIdx];
		}
		// v 부모 배열 만듦
		current_nodeIdx = v;
		for (v_length = 0; parent[current_nodeIdx] != 0; v_length++) {
			path_v[u_length] = parent[current_nodeIdx];
			current_nodeIdx = parent[current_nodeIdx];
		}

		do {
			u_length--;
			v_length--;
		} while (u_length >= 0 && v_length >= 0 && path_v[v_length] == path_u[u_length]);
		if (u_length >= 0) {
			lca = path_u[u_length];
		}
		if (lca > 0) {
			cout << lca << "\n";
		}
		else {
			cout << "error\n";
		}
	}
}