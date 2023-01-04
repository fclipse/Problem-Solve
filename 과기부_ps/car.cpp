#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define SIZE 1005
using namespace std;

int stationLoc[SIZE] = { 0 };
int main() {
	fastIO;
	int K, M, k;
	cin >> K >> M;
	
	vector<pair<int, int>> carLoc(M);
	for (int i = 0; i < K; i++) {
		cin >> k;
		stationLoc[k]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> carLoc[i].first >> carLoc[i].second;
	}
	// solving
	for (int i = 0; i < M; i++) {
		int currentLoc = carLoc[i].first, length = carLoc[i].second;
		int num = 0;
		for (int j = -length; j <= length; j++) {
			if (currentLoc + j >= 0 && currentLoc + j <= 1000) {
				num += stationLoc[currentLoc + j];
			}
		}
		cout << num << "\n";
	}
	return 0;
}