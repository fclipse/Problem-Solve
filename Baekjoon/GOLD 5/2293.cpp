// Baekjoon No. 2293 동전 1 - 220906~
// Time Complexity O(n*k)
// #DP
// 동전 조합 중복 x 조건을 반복문 내/외를 바꿔서 작성했다면 풀리는 문제
// n을 k번 반복하는거랑 k를 n번 반복하는 것은 다르다.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    int i, j;
    cin >> n >> k;
    vector<int> values(n, 0);
    vector<int> memory(k + 1, 0);

    for (i = 0; i < n; i++)
        cin >> values[i];
            

    // solving
    memory[0] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            if (j + values[i] <= k)
                memory[j + values[i]] += memory[j];
        }
    }

    cout << memory[k];
    return 0;
}