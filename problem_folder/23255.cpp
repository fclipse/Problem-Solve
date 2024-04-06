#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100000
#define MAX_EDGE 400
using namespace std;

/*
* 유니온파인드로 연결된 건물들 집합으로 나누고,
* 각 집합에서 건물의 색깔을 번호 오름차순대로 색상 1부터 오름차순으로 칠하는 문제
* -> 문제를 잘못 이해함
* > 구름다리로 연결되어 있는 두 건물은 다른 색으로 칠한다.
* -> 직접 연결된 건물의 색상만 다르면 됨.
* 
* 문제 - n개의 점들을 각각 방문할때 그 점과 연결된 다른 모든 점들중 색상이 정해진 것들을 제외하고 남은 색상중
* 가장 작은 색상을 알아내야 하는데, 그게 쉽지 않음.
* O(NM)이 최소로 줄일 수 있는 한계..
*/

// globals
int color[MAX] = { 0 };
vector<int> bridges[MAX];
set<int> available[MAX];


int main() {
	fastio;
	int n, m;	// n == nodeNum, m == edgeNum
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {	// i => iterates 0 from m
		int v, w;	// v, w => input 2 node Numbers
		cin >> v >> w;
		v--;
		w--;
		bridges[v].push_back(w);
		bridges[w].push_back(v);
	}
	
	// init available - O(400*n*logn)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_EDGE; j++) {
			available[i].insert(j + 1);
		}
	}
	// solving - O(2NMlgN)
	for (int i = 0; i < n; i++) {
		int bestColor = *(available[i].begin());
		color[i] = bestColor;
		// reflect it to other directly connected nodes
		for (int j = 0; j < bridges[i].size(); j++) {
			int nextIdx = bridges[i][j];
			available[nextIdx].erase(bestColor);
		}
	}
	
	// output
	for (int i = 0; i < n; i++) {
		cout << color[i] << " ";
	}

	return 0;
}