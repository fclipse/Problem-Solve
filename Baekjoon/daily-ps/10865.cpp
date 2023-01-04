#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int dfs(int node, int root, vector<int>& friendsNum, vector<int> &visited, vector<vector<int>>& relations);
int main() {
	fastIO
	int n, m;
	int a, b;
	cin >> n >> m;
	vector<int> friendsNum(n, -1);
	vector<int> visited(n, -1);
	vector<vector<int>> relations(n);
	// init
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		relations[a - 1].push_back(b - 1);
		relations[b - 1].push_back(a - 1);
	}

	// solving
	for (int i = 0; i < n; i++) {
		if (friendsNum[i] < 0) {
			dfs(i + 1, i + 1, friendsNum, visited, relations);
		}
		cout << friendsNum[i] << "\n";
	}
	
	/*
	map<int, vector<int>> group;
	for (int i = 0; i < n; i++) {
		int root = visited[i];
		if (group.find(root) == group.end()) {
			group[root] = { root };
		}
		else {
			group[root].push_back(i + 1);
		}
	}

	cout << "print by Group\n";
	for (int i = 1; i <= n; i++) {
		if (group.find(i) != group.end()) {
			for (int j = 0; j < group[i].size(); j++) {
				cout << group[i][j] << " ";
			}
			cout << "\n";
		}
	}
	*/
	return 0;
}

int dfs(int node, int root, vector<int>& friendsNum, vector<int> &visited, vector<vector<int>>& relations) {
	int cnt = 0;
	visited[node - 1] = root;
	for (int idx : relations[node - 1]) {
		if (visited[idx] < 0) {
			cnt += dfs(idx + 1, root, friendsNum, visited, relations);
		}
	}
	// 시작점만 아니라면 리프 노드인걸로 간주 -> 1반환
	if (node != root) {
		cnt++;
	}
	else{	// 시작점으로 다시 돌아왔을 때, 자신 포함 친구들의 친구 명수 cnt로 맞춰줌
		for (int i = 0; i < relations.size(); i++) {
			if (visited[i] == node) {
				friendsNum[i] = cnt;
			}
		}
	}
	return cnt;
}