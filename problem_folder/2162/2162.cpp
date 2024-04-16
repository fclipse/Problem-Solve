#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 선분의 두 끝점을 저장하는 구조체
typedef struct Segment{
    int x1, x2, y1, y2;
} Segment;

int gcd(int a, int b);
pair<int, int> inclination(Segment s);
// 두 선분이 교차하는지 판정하는 함수
bool isCrossed(Segment s1, Segment s2);
int find(int x, vector<int> &arr);
bool _union(int x1, int x2, vector<int> &arr);

int main() {
	fastio;
    int n;
    cin >> n;
    vector<Segment> lines(n);
    for(int i = 0; i < n; i++){
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
    }
    
    // solving

    // output

	return 0;
}

int gcd(int a, int b){
    if(b > a) swap(a, b);
    if(a % b == 0) return max(b, -b);
    return gcd(b, a % b);
}
// 기울기를 두 정수 dx, dy로 반환하는 함수
pair<int, int> inclination(Segment s){
    int dx = s.x2 - s.x1;
    int dy = s.y2 - s.y1;

}
bool isCrossed(Segment s1, Segment s2){
    
}
int find(int x, vector<int> &arr);
bool _union(int x1, int x2, vector<int> &arr);