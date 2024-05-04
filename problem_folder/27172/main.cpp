#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define SIZE 100000

using namespace std;

// globals
pii arr[SIZE] = {{0, 0}};
pii sorted[SIZE] = {{0, 0}};
int point[SIZE] = {0};   // sorted[] 기준으로 저장

// functions
int binSearch(int x, int st, int ed);

int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    
    // solving
    memcpy(sorted, arr, n * sizeof(pii));
    sort(sorted, sorted + n);
    for (int i = 0; i < n; i++){
        for(int j = 1; j <= sqrt(arr[i].first); j++){
            if(arr[i].first % j == 0){
                int d1 = j;
                int d2 = arr[i].first / j;
                int idx = binSearch(d1, 0, n - 1);
                if(idx >= 0 && arr[idx].first != arr[i].first){
                    point[idx]++;
                    point[i]--;
                }
                if(d1 != d2){
                    idx = binSearch(d2, 0, n - 1);
                    if(idx >= 0 && arr[idx].first != arr[i].first){
                        point[idx]++;
                        point[i]--;
                    }   
                }
            }
        }
    }    
    
    // output
    for (int i = 0; i < n; i++){
        cout << point[i] << " ";
    }
    return 0;
}

// sorted 배열 내에 x가 있는지 이진탐색으로 확인하는 함수
int binSearch(int x, int st, int ed){
    if(sorted[st].first > x || sorted[ed].first < x) return -1;
    int mid = (st + ed) / 2;
    int pivot = sorted[mid].first;
    if(pivot == x) return sorted[mid].second;
    else if(pivot > x) return binSearch(x, st, mid - 1);
    else return binSearch(x, mid + 1, ed);
}

// 아이디어 2.
// memcpy(sorted, arr, n * sizeof(pii));
// sort(sorted, sorted + n);
// // cout << "sorted" << endl;
// // for (int i = 0; i < n; i++){
// //     cout << sorted[i].first << " : " << sorted[i].second << ", ";
// // }
// // cout << endl;

// for (int i = 0; i < n; i++){
//     bool divided = false;
//     for (int j = 0; j < divisor.size(); j++){
//         int x = sorted[i].first;
//         int xIdx = sorted[i].second;
//         if(n % divisor[j].back().first == 0){
//             divided = true;
//             // point 정산
//             point[xIdx] -= divisor[j].size();
//             for(pii t : divisor[j]){
//                 point[t.second]++;
//             }
//             divisor[j].push_back(sorted[i]);
//         }   
//     }
//     // 그 이전의 어떤걸로도 나눌 수 없는 경우
//     if(!divided){
//         divisor.push_back({sorted[i]});
//     }
// }