#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100

using namespace std;
// 240418 solved
// dfs

// globals
int n;
int arr[SIZE][SIZE] = {0};
bool checked[SIZE][SIZE] = {0};

// fuctions
void dfs(int x, int y, int seaLevel);
void initChecked();

int main() {
	fastio;
    int maxNum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            maxNum = max(maxNum, arr[i][j]);
        }
    }

    // solving
    int areaNum = 0;
    int maxAreaNum = 0;
    for(int seaLevel = 0; seaLevel < maxNum; seaLevel++){
        areaNum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] > seaLevel && !checked[i][j]){
                    areaNum++;
                    dfs(j, i, seaLevel);
                }
            }
        }
        maxAreaNum = max(maxAreaNum, areaNum);
        initChecked();
        // cout << "areaNum : " << areaNum << endl;
    }
    

    // output
    cout << maxAreaNum;

	return 0;
}

// 한 영역을 칠하는 함수
void dfs(int x, int y, int seaLevel){
    checked[y][x] = true;
    vector<pair<int, int>> delta = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };
    for(int i = 0; i < 4; i++){
        int dx = delta[i].first;
        int dy = delta[i].second;
        int x1 = x + dx;
        int y1 = y + dy;
        if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n){
            if(!checked[y1][x1] && arr[y1][x1] > seaLevel){
                dfs(x1, y1, seaLevel);
            }
        }
    }
    return;
}

void initChecked(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            checked[i][j] = false;
        }
    }
    return;
}