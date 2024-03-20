#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define YMAX 100
#define XMAX 1000
using namespace std;

/*
* 1. 마크 좌우 대칭
* 2. W, Y, B중 하나로 색칠되어야함, 특히 테두리는 B로(이건 기본적으로 이렇게 나옴)
* 3. 마크는 흰색문양 2개, 노란문양 1개, 파란문양 1개로 이루어져야함.
* 4. 두 흰색 문양은 중앙 기준 좌우대칭이어야 함
* 5. 모든 흰색 문양은 노란색 문양과 한 칸 이상 변을 공유해야 함
* 
* - 최소크기 3 * 5 -> 테두리 제외하면 1 * 3
*/

// globals
int y, x;
string mark[YMAX];
bool isVisited[YMAX][XMAX] = { 0 };

// functions
int areaNum();
void checkCell(int, int);
void printMark();

int main() {
	fastio;
	// input
	cin >> y >> x;
	cin.ignore();	// remove buffer
	for (int i = 0; i < y; i++) {
		getline(cin, mark[i]);
	}
	// solving
	// 0. 테두리 B로 초기화(혹시몰라서)
	for (int i = 0; i < y; i++) {
		mark[i][0] = 'B';
		mark[i][x - 1] = 'B';
	}
	for (int j = 0; j < x; j++) {
		mark[0][j] = 'B';
		mark[y - 1][j] = 'B';
	}

	// 1. 주어진 mark에서 Blue부분 대칭으로 만듦 - 테두리는 검사 x(어차피 전부 B로줌)
	for (int i = 1; i < y - 1; i++) {
		for (int j = 1; j < x / 2; j++) {
			// 대칭인 두 칸 중 하나가 B색상이면 나머지 하나도 B색상으로 맞춰줌
			if (mark[i][j] != mark[i][x - 1 - j]) {
				mark[i][j] = 'B';
				mark[i][x - 1 - j] = 'B';
			}
		}
	}
	// printMark();	// debug
	// 2. 남은 X로 되어있는 공간이 '하나'만 있는지 검사
	int areas = areaNum();
	if (areas != 1) {
		// cout << "areas : " << areas << endl;
		cout << "NO";
		return 0;
	}
	// 3. 남은 공간 중 x값기준 양 끝단 맨 위의 한 점만 W로 찍고 나머진 Y로 찍음
	bool isPicked = false;
	for (int j = 1; j < x / 2; j++) {
		for (int i = 1; i < y - 1; i++) {
			int x_opp = x - 1 - j;	
			// 반대편이랑은 한 칸 이상 떨어져있어야함
			if (x_opp - j > 1 && mark[i][j] == 'X') {
				mark[i][j] = 'W';
				mark[i][x_opp] = 'W';
				isPicked = true;
				break;
			}
		}
		if (isPicked) {
			break;
		}
	}
	// 남은 공간 Y로 채움
	for (int i = 1; i < y - 1; i++) {
		for (int j = 1; j < x - 1; j++) {
			if (mark[i][j] == 'X') {
				mark[i][j] = 'Y';
			}
		}
	}

	// 4. 검사해서 안되면 NO 출력
	// 흰 영역 2개면서 대칭인지, Y영역과 인접하는지만 검사하면 됨
	// Y영역과 인접할수밖에 없음 -> X영역이 1개였기 때문!
	/*
	* 흰 영역을 찍지 못했다는 뜻 
	* - x값 홀수고 가운데 한줄만 남아있었거나
	* - x값 짝수고 x/2, x/2+1인 두 인접한 곳에 찍어야 하는 경우
	*/ 
	if (!isPicked) {
		cout << "NO";
		return 0;
	}

	
	cout << "YES\n";
	// output
	printMark();
	
	return 0;
}

// X로 되어있는 공간의 개수 반환, 테두리는 검사 x
int areaNum() {
	int areaCnt = 0;
	for (int i = 1; i < y - 1; i++) {
		for (int j = 1; j < x - 1; j++) {
			// 방문 x시에만
			if (mark[i][j] == 'X' && !isVisited[i][j]) {
				checkCell(j, i);
				areaCnt++;
			}
		}
	}
	return areaCnt;
}

// 재귀적으로 인접한 영역 표시
void checkCell(int px, int py) {
	isVisited[py][px] = true;
	int xArr[] = { 1, -1, 0, 0 }, yArr[] = {0, 0, 1, -1};
	for (int i = 0; i < 4; i++) {
		int x_after = px + xArr[i], y_after = py + yArr[i];
		if (x_after >= 0 && x_after < x && y_after >= 0 && y_after < y 
			&& !isVisited[y_after][x_after] && mark[y_after][x_after] == mark[py][px]) {
			checkCell(x_after, y_after);
		}
	}
	return;
}

// mark배열 출력
void printMark() {
	for (int i = 0; i < y; i++) {
		cout << mark[i] << "\n";
	}
	return;
}