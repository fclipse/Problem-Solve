// Baekjoon No. 3273 두 수의 합
// Time Complexity O(n)
// #DP
// 서로 다른 정수 n개 중 서로 다른 2개를 조합해 x를 만들 수 있는 쌍을 출력하는 프로그램

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    int i;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    vector<int> memory(x + 1, 0);

    // solving
    for (i = 0; i < n; i++) {
        if(arr[i] < x)
            memory[arr[i]] = 1;
        if (x - arr[i] > 0 && arr[i] * 2 != x && memory[x - arr[i]])
            memory[x] ++;
    }
    cout << memory[x];

    return 0;
}