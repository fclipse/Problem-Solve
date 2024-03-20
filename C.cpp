#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

// constants
constexpr ll INF = 9000000000000000000;
constexpr int LEN = 50;
constexpr int MAX = 1000000;
using namespace std;

/*
* - start, end가 정해진 상태에서 start~end까지 가는데 sum(차이^2) 최소값 구하는 문제
* -> 최단거리 구하는 문제와 비슷 => 경로^2 합 최소화 문제
* 
* 1. 각 진법간 피로도 차이(다른 칸 개수 ^2)를 전부 저장 -> O(F * F / 2 *N*M) <= 3,125,000
*	- 그 과정에서 각 진법별로 차이 오름차순으로 정렬 가능?  => 진법마다 O(nlogn) 
*	-> O(F * NlogN) = O(F * FlogF)
* //2. 다익스트라 알고리즘 사용해서 start부터 end까지의 최소거리(피로도^2 최소)구함
*	// - 각 날마다 시연할 진법 선정 -> O(L * T * F * N * M)
*	2.1. 다익스트라 사용하면 O(F*logF)만에 가능
*   => 총 O(F*F*logF) <= 2500*lg50 ~= 14109
*	2.2. 플로이드 와셜 사용 -> O(F*F*F)에서 가능
*	=> 총 O(F^4) <= 6.25*10^6
* 
* 2. 다익스트라 안됨 -> 결국 T개의 경로를 거쳐 i부터 j까지 가는 최단거리를 구하는 알고리즘이 필요함.
* 
* - 피로도 최대차 = 6250000,
* - 하루에 나올 수 있는 피로도 최대차 -> 6250000,
* - l <= 1000000 => 피로도 합 <= 6250000 * 1000000 = 6.25*10^12 = 약 60조 < 9*10^18
* => long long 가능
* 
* - 명목상 T <= 10^6이지만, T는 50^2까지밖에 의미가 없음.
* - 그 이상 넘어가도 결국 C[i]와  C[j]의 조합은 최대 50임 => F<=50이므로
* 
* - L도 마찬가지. 
*/

// globals
int formNum, l, t, n, m;
bool formation[LEN][LEN][LEN] = { 0 };	// 진법 정보 저장

int firstFormIdx[MAX] = { 0 };
int lastFormIdx[MAX] = { 0 };	// 날짜별 마지막 formation idx
int tiredValArr[LEN][LEN];
// 각 idx별로 우선순위큐 이용해 {거리, idx} 저장, 음수로 값 저장 -> minheap
priority_queue<pair<int, int>> minTiredValArr[LEN];

// functions
int getTiredVal(int, int);
void getOptimalTiredValSum(int, int, int, ll*, ll currentTiredVal);

int main() {
	fastio;
	// init
	cin >> formNum >> l >> t >> n >> m;
	// inputs formation
	for (int fIdx = 0; fIdx < formNum; fIdx++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> formation[fIdx][i][j];
			}
		}
	}
	// inputs other variables
	for (int i = 0; i < l; i++) {
		cin >> lastFormIdx[i];	// i + 1번째 날에 마지막으로 시연할 formation의 number 저장
		lastFormIdx[i]--;		// 번호로 주므로 1씩 빼줌
	}

	// firstFormIdx 초기화
	firstFormIdx[0] = 0;
	for (int i = 1; i < l; i++) {
		firstFormIdx[i] = lastFormIdx[i - 1];
	}
	// case 1. T == 1일때
	long long ans = 0;

	// 1. 피로도 배열 초기화 - O(F^2 / 2 * N*M * lgF) <= 4*10^7
	for (int i = 0; i < formNum; i++) {
		for (int j = 0; j < i; j++) {	// 왼쪽 아래 삼각형 부분만 구함
			if (i != j) {
				int tiredVal = getTiredVal(i, j);	// O(N*M)
				tiredValArr[i][j] = tiredVal;
				tiredValArr[j][i] = tiredVal;
				minTiredValArr[i].push({ -tiredVal, j });	// O(lgF)
				minTiredValArr[j].push({ -tiredVal, i });
			}
		}
	}

	cout << "TiredValArr making Finished\n";
	for (int i = 0; i < formNum; i++) {
		for (int j = 0; j < formNum; j++) {
			cout << tiredValArr[i][j] << " ";
		}
		cout << "\n";
	}

	// 2. 각 날짜별 피로도 최솟값 구함
	
	for (int i = 0; i < l; i++) {
		cout << "current Date - " << i << "\n";
		int lfIdx = lastFormIdx[i], ffIdx = firstFormIdx[i];
		ll minTiredValSum = INF;
		vector<int> arr(t, 0);
		for (int p = 0; p < t; p++) {

		}

		ans += minTiredValSum;
	}

	cout << ans;
	return 0;
}

// 두 formation간 피로도 구해주는 함수, O(n * m)
int getTiredVal(int form1, int form2) {
	int diff = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (formation[form1][i][j] != formation[form2][i][j]) {
				diff++;
			}
		}
	}
	return diff * diff;
}

// start 부터 end 사이 tLeft 개의 노드를 거쳐 얻을 수 있는 최소 tiredVal을 구함
void getOptimalTiredValSum(int st, int ed, int tLeft, ll* minTiredValSum, ll currentTiredVal) {
	cout << "solving - " << tLeft << " th st - " << st << " ed - " << ed << "\n";
	if (tLeft == 1) {
		*minTiredValSum = min(*minTiredValSum, currentTiredVal + tiredValArr[st][ed]);
		return;
	}
	for (int midIdx = 0; midIdx < formNum; midIdx++) {	
		int cost = -minTiredValArr[st].top().first;
		// 현재까지의 합이 이전 정답보다 크면 다음 단계로 보내지 않음
		if (currentTiredVal + cost <= *minTiredValSum) {
			getOptimalTiredValSum(midIdx, ed, tLeft - 1, minTiredValSum, currentTiredVal + cost);
		}
		else {
			cout << "not opimal\n";
		}
	}

	return;
}