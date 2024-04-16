#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INIT_VALUE 2000000000

using namespace std;

// function
int binSearch(int baseValue, int st, int ed, vector<int> &arr);

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> lis(n, INIT_VALUE);
    vector<int> lis_backup(n, -1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    int length = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int idx = binSearch(arr[i], 0, n - 1, lis);
        if(idx >= 0){
            lis[idx] = arr[i];
            lis_backup[i] = idx;
            length = max(length, idx + 1);
        }
    }
    
    int targetIdx = length - 1;
    for(int i = 0; i < n; i++){
        if(lis_backup[n - i - 1] == targetIdx){
            ans[targetIdx] = arr[n - i - 1];
            targetIdx--;
        }
        if(targetIdx == -1) break;
    }
    // output
    cout << length << "\n";
    for(int i = 0; i < length; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

// 자신보다 큰 수들 중 가장 작은 값의 위치를 return 함
// 만약 자기 자신이 이미 있다면 -1을 return함
int binSearch(int baseValue, int st, int ed, vector<int> &arr){
    if(arr[st] > baseValue) return st;
    if(arr[ed] <= baseValue) return -1;
    int mid = (st + ed) / 2;
    int pivot = arr[mid];
    if(pivot == baseValue) return -1;
    else if(pivot < baseValue) return binSearch(baseValue, mid + 1, ed, arr);
    else return binSearch(baseValue, st, mid, arr);
}