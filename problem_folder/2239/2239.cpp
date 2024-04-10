#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// globals
int sudoku[9][9] = {0};

// functions
bool isAvailable(int n, int x, int y);
bool dfs(int x, int y);

int main() {
	fastio;
    // vector<vector<int>> sudoku(9, vector<int>(9));
    for(int i = 0; i < 9; i++){
        string str;
        getline(cin, str);
        for(int j = 0; j < 9; j++){
            sudoku[i][j] = str[j] - '0';
        }
    }

    // solving
    dfs(0, 0);

    // output
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j];
        }
        cout << "\n";
    }
	return 0;
}

// 해당 위치에 n이 들어갈 수 있나 확인
bool isAvailable(int n, int x, int y){
    // 가로, 세로 확인
    for(int i = 0; i < 9; i++){
        if(sudoku[y][i] == n) return false;
        if(sudoku[i][x] == n) return false;
    }
    // 해당 블록 확인
    int x1 = x / 3 * 3;
    int y1 = y / 3 * 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sudoku[y1 + i][x1 + j] == n) return false;
        }
    }
    return true;
}

bool dfs(int x, int y){
    // cout << "( " << x << " " << y << " )\n";
    // 해당 위치가 비어있을 때
    if(sudoku[y][x] == 0){
        for(int n = 1; n <= 9; n++){
            if(isAvailable(n, x, y)){
                sudoku[y][x] = n;
                if(!dfs(x, y)){
                    sudoku[y][x] = 0;
                }else{
                    return true;
                }
            }
        }
        // 다 안될때
        return false;
    }

    // 아무것도 못들어갈때 false return
    // 만약 해당 위치가 비어있지 않다면 가장 가까운 다음 위치로 이동, dfs 재개
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                return dfs(j, i);
            }
        }
    }
    // 전부 채워졌을때
    return true;
}
