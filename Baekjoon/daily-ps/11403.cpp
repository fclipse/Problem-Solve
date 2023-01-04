#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void matrixBooleanMultiplication(vector<vector<bool>>& node);
void checkReflection(vector<vector<bool>>& node);
bool isSame(vector<vector<bool>> &m1, vector<vector<bool>> &m2);
void printMatrix(vector<vector<bool>>& m) {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	fastio
	int n;
	int tmp;
	cin >> n;
	vector<vector<bool>> node(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			node[i][j] = tmp;
		}
	}

	// solving
	matrixBooleanMultiplication(node);
	checkReflection(node);

	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << node[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

void matrixBooleanMultiplication(vector<vector<bool>>& node) {
	int n = node.size();
	vector<vector<bool>> res(node);
	vector<vector<bool>> tmp(node);
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = res[i][j] | node[j][i];
			}
		}

		if (!isSame(tmp, res)) {
			res = vector<vector<bool>>(tmp);
		}
		else {
			node = vector<vector<bool>>(tmp);
			break;
		}
	}
	return;
}

void checkReflection(vector<vector<bool>>& node) {
	int n = node.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (node[i][j] && node[j][i]) {
				node[i][i] = 1;
				break;
			}
		}
	}
}

bool isSame(vector<vector<bool>>& m1, vector<vector<bool>>& m2) {
	int n = m1.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m1[i][j] != m2[i][j]) {
				return false;
			}
		}
	}
	return true;
}

