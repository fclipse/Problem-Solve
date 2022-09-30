// Baekjoon No. 10815 숫자 카드 - 220911
// Time Complexity O(nlogn)
// #Binary Search #map

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int findNum);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int i;
    cin >> n;
    vector<int> cards(n);
    for (i = 0; i < n; i++)
        cin >> cards[i];
    cin >> m;
    vector<vector<int>> numbers(m, vector<int>(2, 0));
    for (i = 0; i < m; i++) {
        cin >> numbers[i][0];
    }       

    // solving
    sort(cards.begin(), cards.end());
    for (i = 0; i < m; i++)
        if (binarySearch(cards, numbers[i][0]))
            numbers[i][1] = 1;

    // output
    for (i = 0; i < m; i++)
        cout << numbers[i][1] << " ";
    return 0;
}
int binarySearch(vector<int>& arr, int findNum) {
    int st = 0, ed = arr.size() - 1, pivot;
    while (st <= ed) {
        pivot = (st + ed) / 2;
        if (findNum == arr[pivot])
            return 1;
        else if (findNum < arr[pivot])
            ed = pivot - 1;
        else
            st = pivot + 1;
    }
    return 0;
}