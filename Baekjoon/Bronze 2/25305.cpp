// Baekjoon No. 25305
// Time Complexity O(n^2)
// #Sort
// 정렬 후 뒤에서 k번째 사람을 찾으면 되는 문제.
#include <iostream>
#include <vector>
using namespace std;
void swap(int*, int*);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    int i, j;
    cin >> n >> k;
    vector<int> arr(n);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // solving, insertion Sort
    for (i = 1; i < n; i++) {
        for (j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }

    // output
    cout << arr[n - k];
    return 0;
}

void swap(int* n, int* m) {
    if (*n == *m)
        return;
    *n ^= *m;
    *m ^= *n;
    *n ^= *m;
    return;
}