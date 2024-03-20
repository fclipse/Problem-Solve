// Baekjoon No. 2750
// Time Complexity O(n^2)
// #Sort

#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
void bubbleSort(vector<int>& arr);
void swap(int* n, int* m);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int i;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // insertion sort로 구현
    bubbleSort(arr);

    // output
    for (i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return 0;
}
// xor swap은 두 수가 같은 시 제대로 이루어지지 않음.
void swap(int* n, int* m) {
    *n ^= *m;
    *m ^= *n;
    *n ^= *m;
    return;
}
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }
    return;
}

void selectionSort(vector<int>& arr) {
    int minIdx;
    for (int i = 0; i < arr.size() - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[minIdx] > arr[j])
                minIdx = j;
        }
        if(i != minIdx)
            swap(&arr[i], &arr[minIdx]);
    }
    return;
}

void bubbleSort(vector<int>& arr) {
    int maxIdx;
    for (int i = arr.size() - 1; i > 0; i--) {
        maxIdx = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[maxIdx] < arr[j])
                maxIdx = j;
        }
        if (i != maxIdx)
        swap(&arr[maxIdx], &arr[i]);
    }
    return;
}