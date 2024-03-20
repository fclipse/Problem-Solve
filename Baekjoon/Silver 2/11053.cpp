// Baekjoon No. 11053 - 가장 긴 증가하는 부분 수열, 221102 solved
// Time Complexity O(nlogn)
// #DP

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    fastIO
    int n;
    int i;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> L;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // solving
    vector<int>::iterator iter;
    L.push_back(arr[0]);
    for (i = 1; i < n; i++) {
        if (L.back() < arr[i])
            L.push_back(arr[i]);
        else {
            iter = lower_bound(L.begin(), L.end(), arr[i]);
            *iter = arr[i];
        }
    }

    cout << L.size();

    return 0;
}
