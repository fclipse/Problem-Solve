#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 선분의 두 끝점을 저장하는 구조체
typedef struct Segment{
    int x1, x2, y1, y2;
} Segment;

// 최대공약수 구하는 함수, a, b 음수여도 됨.
int gcd(int a, int b);
// 선분의 기울기를 {dx, dy}로 반환하는 함수
pair<int, int> inclination(Segment s);
// 직선의 방정식을 이용해 {x, y}가 s 위 / 아래 / 선분 위 중 어디있는지 판정하는 함수
int lineFunction(int x, int y, Segment s);
// 두 선분이 교차하는지 판정하는 함수
bool isCrossed(Segment s1, Segment s2);
int find(int x, vector<int> &parent);
bool _union(int x1, int x2, vector<int> &parent, vector<int> &rank);

int main() {
	fastio;
    int n;
    cin >> n;
    
    vector<int> parent(n);
    vector<int> rank(n, 1); // 이건 1로 초기화
    vector<Segment> lines(n);
    vector<vector<bool>> isCrossing(n, vector<bool>(n, 0));
    for(int i = 0; i < n; i++){
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
    }
    
    // solving
    int groupNum = 0;
    int maxGroupSize = 0;
    
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    // 1. n*n의 교차하는지 표를 만듦 - O(N^2)
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(i == j){
                isCrossing[i][j] = 1;
                continue;
            }
            isCrossing[j][i] = isCrossing[i][j] = isCrossed(lines[i], lines[j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << isCrossing[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 2. 유니온 파인드로 그룹을 지음 - O(N^2)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){ // 자기 자신은 포함 x
            if(isCrossing[i][j]){
                _union(i, j, parent, rank);
            }
        }
    }

    // 3. 각 그룹을 방문하면서 각 그룹의 크기와 개수를 셈
    for(int i = 0; i < n; i++){
        if(rank[i] > 0){
            groupNum++;
            maxGroupSize = max(maxGroupSize, rank[i]);
        }
    }

    // output
    cout << groupNum << "\n" << maxGroupSize;

	return 0;
}

// gcd(a, b) == gcd(-a, b)
int gcd(int a, int b){
    a = max(a, -a);
    b = max(b, -b);
    if(b > a) swap(a, b);
    if(a % b == 0) return max(b, -b);
    return gcd(b, a % b);
}

// 기울기를 두 정수 dx, dy로 반환하는 함수
pair<int, int> inclination(Segment s){
    int dx = s.x2 - s.x1;
    int dy = s.y2 - s.y1;
    // int g = gcd(dx, dy);    // g > 0
    // dx /= g;
    // dy /= g;
    return {dx, dy};
}

int lineFunction(int x, int y, Segment s){
    pair<int, int> m = inclination(s);
    int dx = m.first, dy = m.second;
    return dy * x - dx * y + dx * s.y1 - dy * s.x1;
}

// 두 선분이 교차하는지 판정하는 함수
bool isCrossed(Segment s1, Segment s2){
    // 근데 직선의 방정식 위에 있지만 점이 선분 위에 없는 경우는?
    // -> 그래도 상관없음. 서로가 서로를 교차하는지 확인하면 됨.
    return lineFunction(s2.x1, s2.y1, s1) * lineFunction(s2.x2, s2.y2, s1) <= 0 && lineFunction(s1.x1, s1.y1, s2) * lineFunction(s1.x2, s1.y2, s2) <= 0;
}

int find(int x, vector<int> &parent){
    if(parent[x] == x) return x;
    // 경로 압축 사용
    return parent[x] = find(parent[x], parent);
}

bool _union(int x1, int x2, vector<int> &parent, vector<int> &rank){
    int r1 = find(x1, parent), r2 = find(x2, parent);
    if(r1 == r2) return false;
    // parent[x1] = parent[x2] = min(r1, r2);    // ?
    if(rank[r1] >= rank[r2]){
        parent[r2] = r1;
        rank[r1] += rank[r2];
        rank[r2] = 0;
    }else{
        parent[r1] = r2;
        rank[r2] += rank[r1];
        rank[r1] = 0;
    }
    return true;
}