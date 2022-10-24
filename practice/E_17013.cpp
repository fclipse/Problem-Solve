// Baekjoon No. 17013
// Time Complexity
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    fastIO;
    int v = 0, h = 0;
    int i, j;
    int marks[2][2] = { {1, 2}, {3, 4} };
    string orders;
    cin >> orders;
    for (i = 0; i < orders.length(); i++) {
        if (orders[i] == 'H') v = 1 - v;
        else h = 1 - h;
    }
    if (v) {
        // switches [0][0], [1][0]
        marks[0][0] ^= marks[1][0];
        marks[1][0] ^= marks[0][0];
        marks[0][0] ^= marks[1][0];
        // switches [0][1], [1][1]
        marks[0][1] ^= marks[1][1];
        marks[1][1] ^= marks[0][1];
        marks[0][1] ^= marks[1][1];
    }
    if (h) {
        // switches [0][0], [0][1]
        marks[0][0] ^= marks[0][1];
        marks[0][1] ^= marks[0][0];
        marks[0][0] ^= marks[0][1];
        // switches [1][0], [1][1]
        marks[1][0] ^= marks[1][1];
        marks[1][1] ^= marks[1][0];
        marks[1][0] ^= marks[1][1];
    }
    for (i = 0; i < 2; i++) {
        cout << marks[i][0] << " " << marks[i][1] << "\n";
    }
    return 0;
}