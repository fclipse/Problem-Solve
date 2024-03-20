// Baekjoon No. 4181 Convex hull - 220921~
// Time Complexity
// #Convex hull, CCW

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#define SIZE 100000
using namespace std;

int coord[SIZE][2] = {0};

int ccw(int, int, int, int, int, int);
bool compY(int *i, int *j);
bool compX(int* i, int* j);
bool compAngle(int* v, int* w);
double retrieveAngleCos(int* i, int* j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y, cnt = 0;
    char c;
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x >> y >> c;
        if (c == 'Y') { // Y일 경우에만 push
            coord[cnt][0] = y;
            coord[cnt++][1] = x;
        }   
    }
    // solving
    /*
    for (i = 0; i < coord.size(); i++)
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    */
    // 1) y sort
    stable_sort(coord, coord + cnt, compY);
    // 2) x sort
    stable_sort(coord, coord + cnt, compX);
    // test
    /*
    printf("sorted\n");
    for (i = 0; i < coord.size(); i++)
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    */
    // 3) stack에 2개 넣고, 계속 하나 pop하면서 비교, coord 안에 있는거 다 비교해서 stack에 넣었으면 출력
    stable_sort(coord + 1, coord + cnt, compAngle);
    
    cout << cnt << "\n";
    for (i = 0; i < cnt; i++) {
        cout << coord[i][1] << " " << coord[i][0] << "\n";
    }

    return 0;
}
int ccw(int y1, int x1, int y2, int x2, int y3, int x3) {
    return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}
bool compY(int* i, int* j) {
    return i[0] < j[0];
}
bool compX(int* i, int* j) {
    return i[1] < j[1];
}
// v-a의 각보다 w-a이 각이 더 큰지 판별하는 함수
bool compAngle(int* v, int *w) {
    return retrieveAngleCos(coord[0], v) > retrieveAngleCos(coord[0], w);
}

// y = cosx 값을 리턴하는 함수. x값이 같을 경우를 최솟값으로 만들기 위해 이런 방법 사용.
// 각이 작을수록 작은 값을 리턴. x값이 가장 작은 점을 기준으로 하므로 0 < 각 <= 180임
double retrieveAngleCos(int *i, int *j) {
    if (i[1] == j[1])   // x동일할 경우, y값이 가장 작은 점 기준이므로 180도로 취급
        return -1;
        // else if (i[0] == j[0])  // y동일
        //    return -1;
    else
        return (i[0] - j[0]) / sqrt((i[0] - j[0]) * (i[0] - j[0]) + (i[1] - j[1]) * (i[1] - j[1]));
}