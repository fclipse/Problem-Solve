#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
using namespace std;

// structs
typedef struct{
    int x, y;

    // struct Compare{
    //     bool operator()(const Point &a, const Point &b)const{
    //         if(a.x != b.x){
    //             return a.x < b.x;
    //         }
    //         return a.y < b.y;
    //     }
    // };

    bool operator==(const Point & other) const
    {
        return x == other.x && y == other.y;
    }
}Point;

struct PointHash {
    size_t operator()(const Point& p) const {
        // Combine the hash values of x and y
        // return hash<int>{}(p.x) ^ hash<int>{}(p.y);

        std::size_t h1 = std::hash<int>{}(p.x);
        std::size_t h2 = std::hash<int>{}(p.y);
        return h1 ^ (h2 << 1);

        // size_t seed = 0;
        // boost::hash_combine(seed, p.x);
        // boost::hash_combine(seed, p.y);

        // return seed;
    }
};

typedef struct{
    int dist;
    bool isWallBroke;
    Point p;
}State;

// globals
int n, m;
int minDist = -1;
bool arr[SIZE][SIZE] = {0};
vector<Point> delta = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

// functions
// bool isExist(Point p, unordered_set<Point, PointHash> &s);

int main() {
	fastio;
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string str;
        getline(cin, str);
        for(int j = 0; j < m; j++){
            arr[i][j] = str[j] - '0';
        }
    }
    
    // solving
    // bfs
    bool isWallBroke = false;
    queue<State> q;
    // unordered_set<Point, PointHash> s;

    
    q.push({1, 0, 0, 0});
    while(!q.empty()){
        State top = q.front();
        q.pop();
        int dist = top.dist;
        Point p = top.p;
        // s에서 제거
        // if(isExist(p, s)){
        //     s.erase(p);
        // }

        if(p.x == m - 1 && p.y == n - 1){
            minDist = dist;
            break;
        }

        for(int i = 0; i < delta.size(); i++){
            int x1 = p.x + delta[i].x;
            int y1 = p.y + delta[i].y;
            // if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !isExist({x1, y1}, s)){
            if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n){
                if(!isWallBroke && arr[y1][x1]){
                    // 벽을 뚫는 경우
                    q.push({dist + 1, !isWallBroke, x1, y1});
                }else{
                    q.push({dist + 1, isWallBroke, x1, y1});
                }
            }
        }
    }

    // output
    cout << minDist;

	return 0;
}

// bool isExist(Point p, unordered_set<Point, PointHash> &s){
//     return s.find(p) != s.end();
// }