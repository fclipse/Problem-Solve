// Baekjoon No. 9084 동전 - 220917 solved
// Time Complexity O(m)
// #DP
// 전에 풀었던 2293 동전 문제랑 똑같음

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m;
    int i, j;
    cin >> t;
    for (int test = 0; test < t; test++) {
        // inputs
        cin >> n;
        vector<int> money(n);
        for (i = 0; i < n; i++) {
            cin >> money[i];
        }
        cin >> m;

        // solving
        vector<int> memory(m + 1, 0);
        memory[0] = 1;
        for (i = 0; i < n; i++) {   // money 반복
            for (j = 0; j < m; j++) {   // memory 돌면서 반복
                if (memory[j] && money[i] + j<= m) {
                    memory[money[i] + j] += memory[j];
                }
            }
        }

        // outputs
        cout << memory[m] << "\n";
    }

    return 0;
}