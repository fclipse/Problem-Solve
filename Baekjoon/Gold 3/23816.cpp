// Baekjoon No. 23816 옷걸이걸이걸이 - 2209~220928 solved
// Time Complexity O(logn)
// #math #dp

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int hanger(int h, int n, int m, int cNum);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cNum = 0;
	int i;
	cin >> n >> m;

	cNum = hanger(1, n, m, cNum);
	cout << cNum;
	return 0;
}

int hanger(int h, int n, int m, int cNum) {
	int i = n;
	while (i > 0 && ((m - (int)pow(2, h - 1) * i) < 0 || (m - (int)pow(2, h - 1) * i) % (int)pow(2, h))) {
		i--;
	}
	m -= (int)pow(2, h - 1) * i;

	// 이전 가지에 추가로 다는 옷걸이 갯수 / 2만큼 이전 옷걸이에서 빼줘야 함.
	if(h > 1)
		cNum -= pow(2, h - 2) * i;
	// 옷개수 추가
	if(h < 4)
		cNum += pow(2, h - 1) * i;
	// 다음 가지로 가야하는지 결정
	if (m == 0)
		return cNum;
	else {
		if (i == 0 || h == 4)
			return -1;
		else
			return hanger(h + 1, i, m, cNum);
	}
		
}