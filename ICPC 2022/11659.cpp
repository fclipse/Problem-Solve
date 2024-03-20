// Baekjoon No. 11659 구간 합 구하기 4 - 220917 solved
// Time Complexity O(m)
// #구간합 -> 합 누적

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, st, ed;
    int i, j;
    cin >> n >> m;
    vector<int> arr(n);
    cin >> arr[0];
    for (i = 1; i < n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
        

    for (i = 0; i < m; i++) {
        cin >> st >> ed;
        st--;
        ed--;
        if (st > 0)
            cout << arr[ed] - arr[st - 1] << "\n";
        else
            cout << arr[ed] << "\n";
    }

    return 0;
}