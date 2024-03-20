// Baekjoon No.
// Time Complexity
// #

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpMul(vector<int> i, vector<int> j);
bool cmpSum(vector<int> i, vector<int> j);
bool cmpBackNum(vector<int> i, vector<int> j);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int i;
    cin >> n;
    vector<vector<int>> players(n, vector<int>(6, 0));
    for (i = 0; i < n; i++) {
        cin >> players[i][0] >> players[i][1] >> players[i][2] >> players[i][3];
        players[i][4] = players[i][1] * players[i][2] * players[i][3];
        players[i][5] = players[i][1] + players[i][2] + players[i][3];
    }

    // solving
    stable_sort(players.begin(), players.end(), cmpBackNum);
    stable_sort(players.begin(), players.end(), cmpSum);
    stable_sort(players.begin(), players.end(), cmpMul);

    for (i = 0; i < 3; i++)
        cout << players[i][0] << " ";
    return 0;
}
bool cmpMul(vector<int> i, vector<int> j) {
    return i[4] < j[4];
}
bool cmpSum(vector<int> i, vector<int> j) {
    return i[5] < j[5];
}
bool cmpBackNum(vector<int> i, vector<int> j) {
    return i[0] < j[0];
}