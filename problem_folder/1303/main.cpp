#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

// 240519 solved
// bfs, dfs

// globals
int n, m;
int delta[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
char ground[SIZE][SIZE] = {0};
bool visited[SIZE][SIZE] = {0};

// functions
int dfs(int x, int y, char color);

int main() {
	fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> ground[i][j];  
        }
    }
    // solving
    int alliancePower = 0, enemyPower = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                int groupSize = dfs(j, i, ground[i][j]);
                if(ground[i][j] == 'W'){
                    alliancePower += groupSize * groupSize;
                }else{
                    enemyPower += groupSize * groupSize;
                }
            }
        }
    }
    // output
    cout << alliancePower << " " << enemyPower;

	return 0;
}

// 그룹의 크기를 반환하는 함수
int dfs(int x, int y, char color){
    int tempSum = 0;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++){
        int x1 = x + delta[i][0];
        int y1 = y + delta[i][1];
        if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m
        && !visited[y1][x1] && color == ground[y1][x1]){
            tempSum += dfs(x1, y1, color);
        }
    }
    return tempSum + 1;
}