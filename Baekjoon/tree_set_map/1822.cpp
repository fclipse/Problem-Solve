// Baekjoon No. 1822 - 차집합, 221101 solved
// Time Complexity
/*
* 집합 A에는 속하지만, B에는 속하지 않는 원소(A-B)들을 출력하는 문제
* 
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int main() {
	fastIO
		int aNum, bNum, tmp;
	int i;
	cin >> aNum >> bNum;
	vector<int> ans;
	map<int, int> A;
	map<int, int> B;
	for (i = 0; i < aNum; i++) {
		cin >> tmp;
		A[tmp] = 1;
	}
	for (i = 0; i < bNum; i++) {
		cin >> tmp;
		B[tmp] = 1;
	}

	// solving
	map<int, int>::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++) {
		if (!B[iter->first])
			ans.push_back(iter->first);
	}
	cout << ans.size() << "\n";
	for (i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}