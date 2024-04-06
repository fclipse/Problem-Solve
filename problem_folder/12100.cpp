#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// globals
int maxNum = 0;

// functions
vector<vector<int>> moveMatrix(int direction, vector<vector<int>> matrix);
void setMaxNum(vector<vector<int>> &matrix);
void step(int leftStepNum, vector<vector<int>> matrix);

int main() {
	fastio;
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}

	// solving
	step(5, matrix);

	// output
	cout << maxNum;

	return 0;
}
// 행렬 이동
// 0 - 위, 1 - 오른쪽, 2 - 아래, 3 - 왼쪽
vector<vector<int>> moveMatrix(int direction, vector<vector<int>> matrix){
	int size = matrix.size();
	/**
	 * KEY IDEA
	 * 한 방향으로 움직일 때 결국 같은 방법으로 size번 반복해주면 됨
	 * 결국 한 column의 알고리즘만 짤 수 있으면 그걸 size번 반복하면 되는 것.
	*/
	int init_x, init_y, x, y, dx, dy;
	// 초기 위치 설정
	init_x = x = 0; init_y = y = 0;
	if(direction == 0) init_y = y = size - 1;
	if(direction == 3) init_x = x = size - 1;
	// 이동 방향 설정
	// 각 direction별로 숫자가 움직이는 방향 벡터 저장
	// -를 붙이는건 
	vector<pair<int, int>> delta = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0},
	};
	dx = -delta[direction].first;
	dy = -delta[direction].second;
	// 각 row마다 이동 작업 실행
	for(int row = 0; row < size; row++){
		if(direction % 2 == 0){
			// 위/아래 이동일때
			
		}
		vector<vector<int>> movedArray(2, vector<int>(size, 0));
		// 복사
		for(int i = 0; i < size; i++){
			movedArray[0][i] = matrix[y][x];
			x += dx;
			y += dy;
		}
		// 이동
		for()
	}
}
// 최대 숫자 찾아서 업데이트
void setMaxNum(vector<vector<int>> &matrix){
	int size = matrix.size();
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			maxNum = max(maxNum, matrix[i][j]);
		}
	}
	return;
}

// step마다 할 명령 적음
void step(int leftStepNum, vector<vector<int>> matrix){
	if(leftStepNum == 0) return;
	// 각 방향마다 try 후 각 결과를 다음 step 함수에 전달
	for(int direction = 0; direction < 4; direction++){
		vector<vector<int>> modifiedMatrix = moveMatrix(direction, matrix);
		if(leftStepNum == 1){
			// 마지막으로 옮겨졌을때만 가장 큰 수 검사
			setMaxNum(modifiedMatrix);
		}
		step(leftStepNum - 1, matrix);
	}
	return;
}