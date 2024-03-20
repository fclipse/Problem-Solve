#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
/*
n개의 작업 -> 
i번째 작업은
- ti회 근무 진행 필요
- di일이 지나기 전 작업을 끝내야 함

- 월요일부터 프로젝트 시작함 -> i => 5, 6, 12, 13, ... 7*i + 5와 7*i + 6일이 주말

- 평일에 시간외 -> A점, 주말은 B점
- A점과 B점 적절히 조합해서 정확히 M점 만들어야 함
- A <= B
- 0 <= M <= 100

- 평일근무 - 작업 할 수도 안 할 수도 있음
- 시간외근무 - 무조건 작업 1회 진행함

- 주말 시간외 근무 -> 최소화해야함



output
- 가점을 정확히 M점 얻으며 모든 작업을 마감 기한 이전에 끝낼 수 있는 주말 시간 외 근무의
최소 횟수를 출력해야함.
- 가점을 정확히 M점 얻으며 모든 근무를 마감 기한 이전에 끝낼 수 없으면 -> -1 출력
*/

// 해당 일수까지 할 수 있는 최대 일의 양을 반환
int maxWorkCnt(int daysNum, bool includeWeekend) {
	int maxCnt = 0;
	int weekNum = daysNum / 7 + 1;
	
	maxCnt += (weekNum - 1) * 5 * 2;
	if (includeWeekend) {
		maxCnt += (weekNum - 1) * 2;	// 주말 수 더함
	}
	// 마지막 주간 시간외 개수 카운트
	if (daysNum % 7 > 0) {
		maxCnt += min(5, daysNum % 7) * 2;	// 평일 시간외는 최대 5일까지 더함
		if (includeWeekend) {
			maxCnt += max(0, daysNum % 7 - 5);	// 주말 있으면 더함
		}
	}
	return maxCnt;
}

int main() {
	fastio;
	int n, a, b, m;
	cin >> n >> a >> b >> m;
	vector<int> endDate(n), workCnt(n);
	for (int i = 0; i < n; i++) {
		cin >> endDate[i] >> workCnt[i];
	}
	// solving
	int ans = 0;
	// case 2. n != 1; a, b, m = 0;

	if (workCnt[0] > maxWorkCnt(endDate[0], true)) {
		// 주말 시간외까지 해도 안 끝나는 경우
		cout << -1;
	}
	else if(workCnt[0] > maxWorkCnt(endDate[0], false)) {
		// 주말 시간외까지 해야 작업이 끝나는 경우
		cout << workCnt[0] - maxWorkCnt(endDate[0], false);
	}
	else {
		// 주말 시간외 안해도 되는 경우
		cout << 0;
	}



	return 0;
}