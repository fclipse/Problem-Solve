// Baekjoon No. 2839 - 설탕 배달 220911
// Time Complexity O(n)
// #DP
// buttom-up 방식으로 결국 최소 개수를 저장하도록 함.

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int i;
    cin >> n;
    vector<int> memory(n + 1, -1);
    memory[0] = 0;
    for (i = 0; i < n; i++) {
        if (memory[i] >= 0) {
            if (i + 3 <= n && (memory[i + 3] < 0 || memory[i + 3] > memory[i] + 1))
                memory[i + 3] = memory[i] + 1;
            if (i + 5 <= n && (memory[i + 5] < 0 || memory[i + 5] > memory[i] + 1))
                memory[i + 5] = memory[i] + 1;
        }
    }

    cout << memory[n];
    return 0;
}