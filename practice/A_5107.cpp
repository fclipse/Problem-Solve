// Baekjoon No.
// Time Complexity
// #
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    fastIO;
    int n;
    int i, idx;
    string a, b;
    cin >> n;
    while (n > 0) {
        map<string, int> peopleNum;
        vector<int> unionFind(n);
        idx = 0;
        for (i = 0; i < n; i++) {
            cin >> a >> b;
            if (peopleNum.find(a) == peopleNum.end()) {
                peopleNum[a] = idx++;
            }
            if (peopleNum.find(b) == peopleNum.end()) {
                peopleNum[b] = idx++;
            }
            unionFind[i] = i;
        }
        // solving



        cin >> n;
    }
    return 0;
}