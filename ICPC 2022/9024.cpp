// Baekjoon No. 9024 두 수의 합
// Time Complexity
// #투 포인터

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k;
    int i;
    cin >> t;
    for (int test = 0; test < t; test++) {
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];

        // solving
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;
        int min_diff = -1;
        int cnt = 0;

        while (left < right) {
            if (abs(k - (arr[left] + arr[right])) == min_diff) {
                cnt++;
            }
            else if (abs(k - (arr[left] + arr[right])) < min_diff || min_diff < 0) {
                min_diff = abs(k - (arr[left] + arr[right]));
                cnt = 1;
            }
            
            // 
            if (arr[left] + arr[right] > k) {
                right--;
            }
            else {
                left++;
            }
        }
        // output
        cout << cnt << "\n";
    }
    return 0;
}