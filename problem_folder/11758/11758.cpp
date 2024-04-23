#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// struct
typedef struct{
    int x, y;
}Point;

// function
int ccw(Point v1, Point v2);

int main() {
	fastio;
    Point p[3];
    for(int i = 0; i < 3; i++){
        cin >> p[i].x >> p[i].y;
    }

    // solving
    cout << ccw({p[1].x - p[0].x, p[1].y - p[0].y}, {p[2].x - p[1].x, p[2].y - p[1].y});
	return 0;
}

// 두 벡터를 받아 외적을 계산, ccw방향을 return하는 함수
int ccw(Point v1, Point v2){
    int result = v1.x * v2.y - v2.x * v1.y;

    if(result == 0) return 0;
    return result > 0 ? 1 : -1;
}