// Baekjoon No. 1004 - 어린 왕자 - 220815 solved
// 시작점에서 끝점까지 이동할때 최소 몇 개의 원을 지날 수 있는지를 구하는 문제.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int relation(int cx, int cy, int r, int x, int y);    // 원과 점의 관계를 알려주는 함수
int main(){
    ios::sync_with_stdio(false);
    int t, n, sx, sy, ex, ey, res;
    int i, tc;
    vector<vector<int>> circles(n, vector<int>(3, 0));
    scanf("%d", &t);
    for(tc = 0; tc < t; tc++){
        res = 0;
        scanf(" %d %d %d %d %d", &sx, &sy, &ex, &ey, &n);
        for(i = 0; i < n; i++)
            scanf(" %d %d %d", &circles[i][0], &circles[i][1], &circles[i][2]); // cx, cy, r 저장
        
        // solving
        for(i = 0; i < n; i++){
            // 시작점이랑 도착점이랑 원 포함 결과가 다르다면 ++
            if(relation(circles[i][0], circles[i][1], circles[i][2], sx, sy) != relation(circles[i][0], circles[i][1], circles[i][2], ex, ey))
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
int relation(int cx, int cy, int r, int x, int y){
    double dist = 0;
    dist = sqrt(pow(cx - x, 2) + pow(cy - y, 2));
    // 거리에 따라 안인지 밖인지를 결정. 문제에서 경계에 걸친 경우는 주지 않는다고 함.
    if(dist > r)
        return 1;
    else
        return 0;
}