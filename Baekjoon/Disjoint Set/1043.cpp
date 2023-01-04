// Baekjoon No. 1043 거짓말 - 221102~ 221108
// Time Complexity O(n^2)
/*
* 같은 파티에 있는 사람들끼리 일단 인접 행렬 방식으로 묶은 뒤, 모든 파티 입력을 다 받고 나서 
* 그 다음에 그 파티에 있는 사람들과 그 사람들과 연관된 모든 사람들 중 
* 한 명이라도 진실을 알고 있는 사람이 있는지 dfs로 체크하는 문제.
* 
* 알고리즘보단 구현 문제에 더 느낌이 가까웠음.
* 
* dfs 사용할 때 visited 초기화 꼭 기억하자!
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

// int knowing_status[SIZE + 1] = { 0 };	// 인덱스 1부터 시작
// int party_people[SIZE][SIZE] = { 0 };

int dfs(int idx, int n, vector<vector<int>> &relations, vector<int> &visited, vector<int> &status);
int main() {
	fastIO;
	bool isLieable;
	int n, m, k, tmp, idx, cnt;
	int i, j, l;
	cin >> n >> m >> k;
	vector<int> status(n, 0);
	vector<vector<int>> parties(m);
	vector<vector<int>> relations(n, vector<int>(n, 0));
	for (i = 0; i < k; i++) {
		cin >> tmp;
		status[tmp - 1] = 1;
	}
	for (i = 0; i < m; i++) {
		cin >> tmp;
		// party init
		for (j = 0; j < tmp; j++) {
			cin >> idx;
			parties[i].push_back(idx - 1);
		}
		// inits relations
		for (j = 0; j < tmp; j++) {
			for (l = 0; l < tmp; l++) {
				if (j != l) {
					relations[parties[i][j]][parties[i][l]] = 1;
					relations[parties[i][l]][parties[i][j]] = 1;
				}
			}
		}
	}
	// solving
	cnt = 0;
	for (i = 0; i < m; i++) {
		// party의 각 인원 for문으로 돌면서, visited == 0이라면 dfs돌려서 한 명이라도 status == 1인지 판별
		isLieable = true;
		vector<int> visited(n, 0);
		for (j = 0; j < parties[i].size(); j++) {
			if (!visited[parties[i][j]] && dfs(parties[i][j], n, relations, visited, status)) {
				isLieable = false;
				break;
			}
		}
		if (isLieable) cnt++;
	}

	cout << cnt;
	return 0;
}
int dfs(int idx, int n, vector<vector<int>>& relations, vector<int>& visited, vector<int> &status){
	visited[idx] = 1;
	if (status[idx]) return 1;
	for (int i = 0; i < n; i++) {
		if (relations[idx][i] && !visited[i] && dfs(i, n, relations, visited, status)) {
			return 1;
		}
	}
	return 0;
}