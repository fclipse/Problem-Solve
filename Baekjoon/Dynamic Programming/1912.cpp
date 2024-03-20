// Baekjoon No. 1912 ¿¬¼ÓÇÕ 221108 solved
// Time Complexity O(n)
// #DP
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fastIO;
    int n, minVal, maxVal;
    int i;
    cin >> n;
    vector<int> arr(n);
    cin >> arr[0];
    for (i = 1; i < n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
        
    // solving
    minVal = arr[0];
    maxVal = arr[0];
    for (i = 1; i < n; i++) {
        maxVal = max(max(maxVal, arr[i] - minVal), arr[i]);
        minVal = min(minVal, arr[i]);
    }
    cout << maxVal;

    return 0;
}