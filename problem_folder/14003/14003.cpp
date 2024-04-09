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
    vector<int> lis_backup(n, INIT_VALUE);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    int length = 0;
    for(int i = 0; i < n; i++){
        int idx = binSearch(arr[i], 0, n - 1, lis);
        if(idx >= 0){
            lis[idx] = arr[i];
            length = max(length, idx + 1);
        }
        // lis backup
        if(length == idx + 1){  // idx위치가 length랑 같거나 클 때만 실행됨
            for(int i = 0; i < length; i++){
                lis_backup[i] = lis[i];
            }
        }
    }

    // output
    cout << length << "\n";
    for(int i = 0; i < length; i++){
        cout << lis_backup[i] << " ";
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