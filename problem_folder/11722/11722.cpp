#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 2000000000

using namespace std;

// functions
int binSearch(int n, int st, int ed, vector<int> &arr);

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> lis(n, INF);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] *= -1;
    }

    // solving
    int maxLength = 0;
    for(int i = 0; i < n; i++){
        int idx = binSearch(arr[i], 0, n - 1, lis);
        if(idx >= 0){
            lis[idx] = arr[i];
            maxLength = max(maxLength, idx + 1);
        }
    }


    // output
    cout << maxLength;
    
	return 0;
}

// 자신보다 큰 수들 중 가장 인덱스가 작은 수의 인덱스를 반환하는 함수
// 자신이 이미 있다면 -1 return
int binSearch(int n, int st, int ed, vector<int> &arr){
    if(arr[st] > n) return st;
    if(arr[ed] < n) return -1;
    int mid = (st + ed) / 2;
    int pivot = arr[mid];

    if(pivot == n) return -1;
    else if(pivot < n) return binSearch(n, mid + 1, ed, arr);
    else return binSearch(n, st, mid, arr);

}