#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
using namespace std;

// structs
typedef struct{
    int x, y, cnt;
}Point;

// globals
int original[SIZE][SIZE] = {0};
int result[SIZE][SIZE] = {0};
bool visited[SIZE][SIZE] = {false};

int main() {
	fastio;
    int n, m;
    Point targetPoint = {0, 0, 0};
    memset(result, -1, SIZE * SIZE * sizeof(int));
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> original[i][j];
            if(original[i][j] == 2){
                targetPoint = {j, i};
            }else if(original[i][j] == 0){
                result[i][j] = 0;
            }
        }
    }
    // solving
    queue<Point> q;
    int delta[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    q.push(targetPoint);
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if(!visited[p.y][p.x]){
            result[p.y][p.x] = p.cnt;
            visited[p.y][p.x] = true;
            for (int i = 0; i < 4; i++){
                int x1 = p.x + delta[i][0];
                int y1 = p.y + delta[i][1];
                if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n
                && !visited[y1][x1] && original[y1][x1] > 0){
                    q.push({x1, y1, p.cnt + 1});
                }
            }
        }
    }
    
    // output
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}
