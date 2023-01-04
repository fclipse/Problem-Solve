// BOJ 24453 - 디버깅, 230102 solved
// 관점을 바꿔서 생각해보자
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio;
	/** 
	* n - 작성된 총 코드 줄 수
	* m - 오류가 있는 줄의 개수
	* x - 에티터가 오류를 해결할 수 있는 최소 연속 정상 코드 줄 개수
	* y - 인규가 해결하고 싶은 최소 오류 줄 개수
	* 출력 - 에디터가 해결할 수 있는 최대 오류 개수
	*/
	int n, m, x, y;
	int maxLineNum = 0;
	int minYNum;
	cin >> n >> m;
	vector<int> errorSum(n, 0);	// 각 칸까지마다의 error line 개수 저장
	int idx = 1;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		errorSum[tmp - 1]++;
		for (; idx < tmp - 1; idx++) {
			errorSum[idx] += errorSum[idx - 1];
		}
	}
	for (; idx < n; idx++) {
		errorSum[idx] += errorSum[idx - 1];
	}

	cin >> x >> y;

	// solving
	minYNum = x;
	// 1번째줄~x번째줄까지 error line 개수 셈
	minYNum = min(errorSum[x - 1], minYNum);
	maxLineNum = m - minYNum;
	for (int i = 0; i < n - x; i++) {	// 2+i번째줄~ 1+i+x번째줄까지 error line 개수 셈
		if (minYNum <= y) break;
		// x개의 연속 줄 안에 들어 있는 error line 개수 중 최소 개수 찾음
		minYNum = min(errorSum[i + x] - errorSum[i], minYNum);
		maxLineNum = m - minYNum;
	}

	if (maxLineNum > m - y) {	// == minYNum < y
		cout << m - y;
	}
	else {
		cout << maxLineNum;
	}

	return 0;
}