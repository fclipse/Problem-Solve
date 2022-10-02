// Baekjoon No. 4181 Convex hull - 220921~
// Time Complexity
// #Convex hull, CCW

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
int ccw(int, int, int, int, int, int);
bool compY(vector<int> i, vector<int> j);
bool compX(vector<int> i, vector<int> j);
double retrieveAngleCos(vector<int> i, vector<int> j);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    char c;
    int i, j;
    cin >> n;
    vector<vector<int>> coord;
    for (i = 0; i < n; i++) {
        cin >> x >> y >> c;
        if (c == 'Y')   // Y일 경우에만 push
            coord.push_back(vector<int> { y, x });
    }
    // solving
    for (i = 0; i < coord.size(); i++)
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    // 1) y sort
    stable_sort(coord.begin(), coord.end(), compY);
    // 2) x sort
    stable_sort(coord.begin(), coord.end(), compX);
    // test
    printf("sorted\n");
    for (i = 0; i < coord.size(); i++)
        cout << coord[i][0] << " " << coord[i][1] << "\n";

    // 3) stack에 2개 넣고, 계속 하나 pop하면서 비교, coord 안에 있는거 다 비교해서 stack에 넣었으면 출력
    stack<vector<int>> stack1;
    stack1.push(coord[0]);
    stack1.push(coord[1]);

    stack1.top();

    i = 2;
    while (i < coord.size()) {
        vector<int> first, second;
        first = stack1.top();
        stack1.pop();
        second = stack1.top();
        while (ccw(second[0], second[1], first[0], first[1], coord[i][0], coord[i][1]) < 0) {
            first = second;
            stack1.pop();
            second = stack1.top();
        }
        stack1.push(first);
        stack1.push(coord[i]);

        i++;
    }

    // 4) stack 에서 하나씩 빼면서 다른 stack에 저장, 두 번째 stack은 pop 반복하면서 출력
    stack<vector<int>> reversed_stack;
    while (stack1.size()) {
        reversed_stack.push(stack1.top());
        stack1.pop();
    }
    while (reversed_stack.size()) {
        printf("%d %d\n", reversed_stack.top()[1], reversed_stack.top()[0]);
        stack1.pop();
    }

    return 0;
}
int ccw(int y1, int x1, int y2, int x2, int y3, int x3) {
    return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}
bool compY(vector<int> i, vector<int> j) {
    return i[0] < j[0];
}
bool compX(vector<int> i, vector<int> j) {
    return i[1] < j[1];
}
// v-a의 각보다 w-a이 각이 더 큰지 판별하는 함수
bool compAngle(vector<int> a, vector<int> v, vector<int> w) {
    return retrieveAngleCos(a, v) < retrieveAngleCos(a, w);
}

// y = -cosx - 1값을 리턴하는 함수. x값이 같을 경우를 최솟값으로 만들기 위해 이런 방법 사용.
// 각이 작을수록 작은 값을 리턴. x값이 가장 작은 점을 기준으로 하므로 0 < 각 <= 180임
double retrieveAngleCos(vector<int> i, vector<int> j) {
    if (i[1] == j[1])   // x동일할 경우, y값이 가장 작은 점 기준이므로 180도로 취급
        return 0;
        // else if (i[0] == j[0])  // y동일
        //    return -1;
    else
        return -(i[0] - j[0]) / sqrt((i[0] - j[0]) * (i[0] - j[0]) + (i[1] - j[1]) * (i[1] - j[1])) - 1;
}