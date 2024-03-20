// Baekjoon No. 9426 중앙값 측정
// Time Complexity
// #

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(vector<int>& e1, vector<int>& e2);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    int i;
    vector<unsigned short int> temp(n);
    vector<vector<int>> range(k);
    for (i = 0; i < n; i++) {
        cin >> temp[i];
    }

    for (i = 0; i < k; i++) {
        range[i][0] = i;
        range[i][1] = temp[i];
    }
    sort(range.begin(), range.end(), cmp);

    return 0;
}
bool cmp(vector<int>& e1, vector<int>& e2){
    return e1[1] < e2[1];
}