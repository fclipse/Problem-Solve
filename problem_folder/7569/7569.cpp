#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100

using namespace std;

// 240418 solved
// bfs

// globals
int n, m, h;
int arr[SIZE][SIZE][SIZE] = {0};

// functions
bool checkFinished();
void bfs(int x, int y, int z);

// structs
typedef struct{
    int x, y, z;
}Point;

int main() {
	fastio;
    int minDay = 0;
    int left = 0;
    queue<Point> q;
    cin >> m >> n >> h;
    for(int z = 0; z < h; z++){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                cin >> arr[z][y][x];
                if(arr[z][y][x] == 1){
                    Point p = {x, y, z};
                    q.push(p);
                    left++;
                }
            }
        }
    }

    // solving
    left = q.size();
    while(!q.empty()){
        // day 관련
        if(left == 0){
            minDay++;
            left = q.size();
            // cout << "minDay : " << minDay << endl;
            // for(int z = 0; z < h; z++){
            //     for(int y = 0; y < n; y++){
            //         for(int x = 0; x < m; x++){
            //             cout << arr[z][y][x] << " ";
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
        }
        Point p = q.front();
        q.pop();
        vector<Point> delta = {
            {-1, 0, 0},
            {1, 0, 0},
            {0, -1, 0},
            {0, 1, 0},
            {0, 0, -1},
            {0, 0, 1}
        };
        
        for(int i = 0; i < delta.size(); i++){
            int x1 = p.x + delta[i].x;
            int y1 = p.y + delta[i].y;
            int z1 = p.z + delta[i].z;
            if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && z1 >= 0 && z1 < h){
                if(arr[z1][y1][x1] == 0){
                    arr[z1][y1][x1] = 1;
                    Point p1 = {x1, y1, z1};
                    q.push(p1); 
                }
            }
        }
        left--;
    }

    // output
    bool check = checkFinished();
    if(check) cout << minDay;
    else cout << -1;

	return 0;
}

// 익지 않은 토마토가 있으면 false를 return하는 함수
bool checkFinished(){
    for(int z = 0; z < h; z++){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                if(arr[z][y][x] == 0) return false;
            }
        }
    }
    return true;
}

void bfs(int x, int y, int z){

}