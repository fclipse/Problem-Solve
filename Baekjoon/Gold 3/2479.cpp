// Baekjoon No. 2479 - 경로 찾기 220917~ 220927 solved
// Time Complexity O(n)
// #bfs
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
 
int dist(string, string);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, st, ed, current_node, size;
	int i, j;
	vector<int> current_path;	// saves current_path
	cin >> n >> k;
	vector<string> codes(n);	// code inputs
	vector<int> visited(n, 0);
	vector<vector<int>> node(n);	// relationships of codes
	queue<vector<int>> path_queue;	// saves node path to queue.
	for (i = 0; i < n; i++) {
		cin >> codes[i];
	}
	cin >> st >> ed;
	
	// solving
	st--;
	ed--;	
	// 인접 리스트 방식으로 저장
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (dist(codes[i], codes[j]) == 1) {
				node[i].push_back(j);
			}
		}
	}
	
	// bfs
	path_queue.push({ st });
	current_node = st;
	while(path_queue.size() > 0) {
		current_path = path_queue.front();
		current_node = current_path.back();
		size = node[current_node].size();
		path_queue.pop();
		// if found answer
		if (current_node == ed)
			break;
		// if not visited
		if (!visited[current_node]) {
			visited[current_node] = 1;
			// pushing queue
			for (i = 0; i < size; i++) {
				if (!visited[node[current_node][i]]) {
					current_path.push_back(node[current_node][i]);
					path_queue.push(current_path);
					current_path.pop_back();
				}
			}
		}
	}

	// output
	if (current_node != ed) {
		cout << -1;
	}
	else {
		size = current_path.size();
		for (i = 0; i < size; i++)
			cout << current_path[i] + 1 << " ";
	}
		

	return 0;
}
// returns hamming distance of two integers / O(logn)
int dist(string n1, string n2){
	int distance = 0, size = n1.length();
	for (int i = 0; i < size; i++) {
		if (n1[i] != n2[i]) {
			distance++;
		}
	}
	return distance;
}